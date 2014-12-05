// AddUserDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Bank.h"
#include "AddUserDlg.h"
#include "RegisteDlg.h"
#include "ADOConn.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAddUserDlg dialog


CAddUserDlg::CAddUserDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CAddUserDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CAddUserDlg)
	m_AccountNum = _T("");
	m_Amount = 0.0;
	m_CustomerID = _T("");
	m_Password = _T("");
	m_Password2 = _T("");
	m_BranchName = _T("");
	//}}AFX_DATA_INIT
}


void CAddUserDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAddUserDlg)
	DDX_Text(pDX, IDC_ACCOUNTNUM, m_AccountNum);
	DDX_Text(pDX, IDC_AMOUNT, m_Amount);
	DDX_Text(pDX, IDC_CUSTOMERID, m_CustomerID);
	DDX_Text(pDX, IDC_PASSWORD, m_Password);
	DDX_Text(pDX, IDC_PASSWORD2, m_Password2);
	DDX_Text(pDX, IDC_BRANCHNAME, m_BranchName);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CAddUserDlg, CDialog)
	//{{AFX_MSG_MAP(CAddUserDlg)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CAddUserDlg message handlers

void CAddUserDlg::OnOK() 
{
	// TODO: Add extra validation here
	UpdateData();
	//检查客户是否存在，判断账号是否重复，密码是否为空，金额是否大于0
	CRegisteDlg dlg;
	if(dlg.CheckCustomerID(m_CustomerID)==1)//记录不存在
	{
		AfxMessageBox("该客户不存在，请注册后重新输入");
		GetDlgItem(IDC_CUSTOMERID)->SetWindowText("");
		GetDlgItem(IDC_ACCOUNTNUM)->SetWindowText("");
		GetDlgItem(IDC_BRANCHNAME)->SetWindowText("");
		GetDlgItem(IDC_PASSWORD)->SetWindowText("");
		GetDlgItem(IDC_PASSWORD2)->SetWindowText("");
		GetDlgItem(IDC_AMOUNT)->SetWindowText("");
		return;
	}
	if(CheckAccountNum())
	{
		AfxMessageBox("该账号已经被注册过，请重新输入");
		GetDlgItem(IDC_ACCOUNTNUM)->SetWindowText("");
		GetDlgItem(IDC_BRANCHNAME)->SetWindowText("");
		GetDlgItem(IDC_PASSWORD)->SetWindowText("");
		GetDlgItem(IDC_PASSWORD2)->SetWindowText("");
		GetDlgItem(IDC_AMOUNT)->SetWindowText("");
		return;
	}
	if(!CheckBranch())
	{
		AfxMessageBox("该银行不存在，请重新输入");
		GetDlgItem(IDC_BRANCHNAME)->SetWindowText("");
		GetDlgItem(IDC_PASSWORD)->SetWindowText("");
		GetDlgItem(IDC_PASSWORD2)->SetWindowText("");
		GetDlgItem(IDC_AMOUNT)->SetWindowText("");
		return;
	}
	if(m_Password!=m_Password2)
	{
		AfxMessageBox("两次输入的密码不一致，请重新输入");
		GetDlgItem(IDC_PASSWORD)->SetWindowText("");
		GetDlgItem(IDC_PASSWORD2)->SetWindowText("");
		GetDlgItem(IDC_AMOUNT)->SetWindowText("");
		return;
	}
	if(m_Amount<=0)
	{
		AfxMessageBox("输入的金额不足，请重新输入");
		GetDlgItem(IDC_AMOUNT)->SetWindowText("");
		return;
	}
	InsertAccountNum();
	AfxMessageBox("该客户开户成功");
	CDialog::OnOK();
}

int CAddUserDlg::CheckAccountNum()
{
	_bstr_t vSQL;
	vSQL="select * from account where account_number='"+m_AccountNum+"'";
	CADOConn m_ADOConn;
	_RecordsetPtr m_Recordset;
	m_ADOConn.OnInitADOConn();
	m_Recordset=m_ADOConn.GetRecordset(vSQL);
	if(m_Recordset->adoEOF)//记录集空
	{
		m_ADOConn.ExitConnect();
		return 0;
	}
	else
	{
		m_ADOConn.ExitConnect();
		return 1;
	}
}

void CAddUserDlg::InsertAccountNum()
{
	_bstr_t accountSQL,depositorSQL;
	CString str;
	str.Format("%f",m_Amount);
	accountSQL="insert into account(account_number,account_pswd,branch_name,balance)\
		values('"+m_AccountNum+"','"+m_Password+"','"+m_BranchName+"','"+str+"')";
	depositorSQL="insert into depositor(account_number,customer_id,account_type,access_date,\
		amount) values('"+m_AccountNum+"','"+m_CustomerID+"','save',convert(varchar,getdate()\
		,120),'"+str+"')";
	CADOConn m_ADOConn;

	m_ADOConn.OnInitADOConn();
	m_ADOConn.ExecuteSQL(accountSQL);	//将账号信息插入account表中
	m_ADOConn.ExecuteSQL(depositorSQL);//将记录插入depositor表中
	m_ADOConn.ExitConnect();
}

int CAddUserDlg::CheckBranch()
{
	_bstr_t vSQL;
	vSQL="select * from branch where branch_name='"+m_BranchName+"'";
	CADOConn m_ADOConn;
	_RecordsetPtr m_Recordset;
	m_ADOConn.OnInitADOConn();
	m_Recordset=m_ADOConn.GetRecordset(vSQL);
	if(m_Recordset->adoEOF)//记录集空
	{
		m_ADOConn.ExitConnect();
		return 0;
	}
	else
	{
		m_ADOConn.ExitConnect();
		return 1;
	}
}
