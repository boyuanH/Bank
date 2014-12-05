// TransforDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Bank.h"
#include "TransforDlg.h"
#include "RegisteDlg.h"
#include "ADOConn.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CTransforDlg dialog

extern CString g_CustomerID;

CTransforDlg::CTransforDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CTransforDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CTransforDlg)
	m_DesAccountNum = _T("");
	m_DesAmount = 0.0;
	m_Password = _T("");
	//}}AFX_DATA_INIT
}


void CTransforDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CTransforDlg)
	DDX_Text(pDX, IDC_DESACCOUNTNUM, m_DesAccountNum);
	DDX_Text(pDX, IDC_DESAMOUNT, m_DesAmount);
	DDX_Text(pDX, IDC_PASSWORD, m_Password);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CTransforDlg, CDialog)
	//{{AFX_MSG_MAP(CTransforDlg)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTransforDlg message handlers

void CTransforDlg::OnOK() 
{
	// TODO: Add extra validation here
	UpdateData();
	if(m_DesAmount<=0)
	{
		AfxMessageBox("转账额小于等于0，无法转账");
		return;
	}
	CRegisteDlg dlg;
	if(m_DesAccountNum==g_CustomerID)
	{
		AfxMessageBox("要转入的账号为现在登录的账号，无法转账");
		GetDlgItem(IDC_PASSWORD)->SetWindowText("");
		return;
	}
	if(dlg.CheckUserID(m_DesAccountNum)==1)//检查要转出的账号是否存在，非空返回0，空返回1
	{
		AfxMessageBox("要转入的账号不存在，请确认");
		GetDlgItem(IDC_PASSWORD)->SetWindowText("");
		return;
	}
	if(dlg.QueryBalance()<m_DesAmount)
	{
		AfxMessageBox("余额不足，无法转出");
		GetDlgItem(IDC_PASSWORD)->SetWindowText("");
		return;
	}
	//确认密码
	_bstr_t vSQL="Select * from account where account_number='"+g_CustomerID+"'";
	CADOConn m_ADOConn;
	m_ADOConn.OnInitADOConn(); //打开数据库连接
	_RecordsetPtr m_pRecordset;//定义记录集指针
	m_pRecordset=m_ADOConn.GetRecordset(vSQL);
	CString strPswd;
	_variant_t theValue;
	theValue=m_pRecordset->GetCollect("account_pswd");
	if(theValue.vt!=VT_NULL)
		strPswd=(char *)_bstr_t(theValue);
	if(strPswd!=m_Password)
	{
		AfxMessageBox("输入的密码不正确，无法转账");
		GetDlgItem(IDC_PASSWORD)->SetWindowText("");
		return;
	}
	/***********************************修改转出账号的余额，增加转出的信息****************/
	_bstr_t balanceSQL,depSQL,preBalance,custID;
	//取出先前的余额
	double balance;
	CString strBalance;
	preBalance="select * from account where account_number='"+g_CustomerID+"'";
	m_pRecordset=m_ADOConn.GetRecordset(preBalance);	
	theValue=m_pRecordset->GetCollect("balance");
	if(theValue.vt!=VT_NULL)
		strBalance=(char *)_bstr_t(theValue);
	balance=atof(strBalance);
	balance-=m_DesAmount;//余额减去取款额为新的余额
	CString strA;
	strA.Format("%f",balance);
	balanceSQL="update account set balance='"+strA+"' where\
		account_number='"+g_CustomerID+"'";
	m_ADOConn.ExecuteSQL(balanceSQL);
	////////////////////////////////////////////查询客户id
	custID="select distinct customer_id from account,depositor where account.account_number=\
		depositor.account_number and depositor.account_number='"+g_CustomerID+"'";

	m_pRecordset=m_ADOConn.GetRecordset(custID);	
	theValue=m_pRecordset->GetCollect("customer_id");
	CString m_CustomerId;
	if(theValue.vt!=VT_NULL)
		m_CustomerId=(char *)_bstr_t(theValue);
	//添加存款记录
	CString strAmount;
	strAmount.Format("%f",m_DesAmount);
	depSQL="insert into depositor(account_number,customer_id,account_type,access_date,amount)\
		values('"+g_CustomerID+"','"+m_CustomerId+"','out',\
		convert(varchar,getdate(),120),'"+strAmount+"')";//获取系统时间
	m_ADOConn.ExecuteSQL(depSQL);

	/********************************修改转入账号的余额，增加转入的信息**************/
	preBalance="select * from account where account_number='"+m_DesAccountNum+"'";
	m_pRecordset=m_ADOConn.GetRecordset(preBalance);	
	theValue=m_pRecordset->GetCollect("balance");
	if(theValue.vt!=VT_NULL)
		strBalance=(char *)_bstr_t(theValue);
	balance=atof(strBalance);
	balance+=m_DesAmount;//余额加上转款额为新的余额
	strA.Format("%f",balance);
	balanceSQL="update account set balance='"+strA+"' where\
		account_number='"+m_DesAccountNum+"'";
	m_ADOConn.ExecuteSQL(balanceSQL);
	//////////////////////////////////////查询客户id
	custID="select distinct customer_id from account,depositor where account.account_number=\
		depositor.account_number and depositor.account_number='"+m_DesAccountNum+"'";
	m_pRecordset=m_ADOConn.GetRecordset(custID);	
	theValue=m_pRecordset->GetCollect("customer_id");
	if(theValue.vt!=VT_NULL)
		m_CustomerId=(char *)_bstr_t(theValue);
	//添加存款记录
	depSQL="insert into depositor(account_number,customer_id,account_type,access_date,amount)\
		values('"+m_DesAccountNum+"','"+m_CustomerId+"','in',\
		convert(varchar,getdate(),120),'"+strAmount+"')";//获取系统时间
	m_ADOConn.ExecuteSQL(depSQL);
	///////////////////////////////////////////////////////////////////
	AfxMessageBox("转账成功!");
	
	CDialog::OnOK();
}
