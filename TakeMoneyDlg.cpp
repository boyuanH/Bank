// TakeMoneyDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Bank.h"
#include "TakeMoneyDlg.h"
#include "ADOConn.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CTakeMoneyDlg dialog

extern CString g_CustomerID;

CTakeMoneyDlg::CTakeMoneyDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CTakeMoneyDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CTakeMoneyDlg)
	m_Amount = 0.0;
	//}}AFX_DATA_INIT
}


void CTakeMoneyDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CTakeMoneyDlg)
	DDX_Text(pDX, IDC_TAKEMONEY, m_Amount);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CTakeMoneyDlg, CDialog)
	//{{AFX_MSG_MAP(CTakeMoneyDlg)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTakeMoneyDlg message handlers

void CTakeMoneyDlg::OnOK() 
{
	// TODO: Add extra validation here
	UpdateData();
	if(m_Amount<=0)
	{
		AfxMessageBox("取款额小于等于0，无法取款");
		return;
	}
	//获取系统时间
	//修改account表中的余额，并添加depositor表中的存款记录
	CADOConn m_ADOConn;
	_RecordsetPtr m_pRecordset;
	m_ADOConn.OnInitADOConn();

	_bstr_t balanceSQL,depSQL,preBalance,custID;
	//取出先前的余额
	_variant_t theValue;
	double balance;
	CString strBalance;
	preBalance="select * from account where account_number='"+g_CustomerID+"'";
	m_pRecordset=m_ADOConn.GetRecordset(preBalance);	
	theValue=m_pRecordset->GetCollect("balance");
	if(theValue.vt!=VT_NULL)
		strBalance=(char *)_bstr_t(theValue);
	balance=atof(strBalance);
	balance-=m_Amount;//余额减去取款额为新的余额
	if(balance<0)
		AfxMessageBox("余额不足，无法取款！");
	else
	{
		CString strA;
		strA.Format("%f",balance);
		balanceSQL="update account set balance='"+strA+"' where\
			account_number='"+g_CustomerID+"'";
		m_ADOConn.ExecuteSQL(balanceSQL);
		//查询客户id
		custID="select distinct customer_id from account,depositor where account.account_number=\
			depositor.account_number";
		m_pRecordset=m_ADOConn.GetRecordset(custID);	
		theValue=m_pRecordset->GetCollect("customer_id");
		CString m_CustomerId;
		if(theValue.vt!=VT_NULL)
			m_CustomerId=(char *)_bstr_t(theValue);
		//添加存款记录
		strA.Format("%f",m_Amount);
		depSQL="insert into depositor(account_number,customer_id,account_type,access_date,amount)\
			values('"+g_CustomerID+"','"+m_CustomerId+"','take',\
			convert(varchar,getdate(),120),'"+strA+"')";//获取系统时间
		m_ADOConn.ExecuteSQL(depSQL);
		AfxMessageBox("取款成功!");
	}
	m_ADOConn.ExitConnect();
	CDialog::OnOK();
}
