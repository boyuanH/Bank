// ChangPswd.cpp : implementation file
//

#include "stdafx.h"
#include "Bank.h"
#include "ChangPswd.h"
#include "ADOConn.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CChangPswd dialog

extern CString g_CustomerID;

CChangPswd::CChangPswd(CWnd* pParent /*=NULL*/)
	: CDialog(CChangPswd::IDD, pParent)
{
	//{{AFX_DATA_INIT(CChangPswd)
	m_NewPswd = _T("");
	m_NewPswd2 = _T("");
	m_OldPswd = _T("");
	//}}AFX_DATA_INIT
}


void CChangPswd::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CChangPswd)
	DDX_Text(pDX, IDC_NEWPASSWORD, m_NewPswd);
	DDX_Text(pDX, IDC_NEWPASSWORD2, m_NewPswd2);
	DDX_Text(pDX, IDC_OLDPASSWORD, m_OldPswd);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CChangPswd, CDialog)
	//{{AFX_MSG_MAP(CChangPswd)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CChangPswd message handlers

void CChangPswd::OnOK() 
{
	// TODO: Add extra validation here
	UpdateData();
	if(m_OldPswd=="")
	{
		AfxMessageBox("请输入原始密码");
		return;
	}
	if(m_NewPswd=="")
	{
		AfxMessageBox("请输入新密码");
		return;
	}
	if(m_NewPswd2=="")
	{
		AfxMessageBox("请确认新密码");
		return;
	}
	
	_bstr_t pswdSQL="Select * from account where account_number='"+g_CustomerID+"'";
	_bstr_t vSQL="Update account set account_pswd='"+m_NewPswd+"'	where\
		account_number='"+g_CustomerID+"'";
	CADOConn m_adoConn;
	_RecordsetPtr m_pRecordset;//定义记录集指针
	m_adoConn.OnInitADOConn();
	//核实密码
	m_pRecordset=m_adoConn.GetRecordset(pswdSQL);
	CString strPswd;
	_variant_t theValue;
	theValue=m_pRecordset->GetCollect("account_pswd");
	if(theValue.vt!=VT_NULL)
		strPswd=(char *)_bstr_t(theValue);
	if(strPswd!=m_OldPswd)//密码不正确
	{
		AfxMessageBox("原始密码不正确，无法修改");
		GetDlgItem(IDC_PASSWORD)->SetWindowText("");
		GetDlgItem(IDC_NEWPASSWORD)->SetWindowText("");
		GetDlgItem(IDC_NEWPASSWORD2)->SetWindowText("");
		return;
	}
	if(m_NewPswd!=m_NewPswd2)
	{
		AfxMessageBox("两次输入的密码不一致，请重新输入");
		GetDlgItem(IDC_NEWPASSWORD)->SetWindowText("");
		GetDlgItem(IDC_NEWPASSWORD2)->SetWindowText("");
		return;
	}
	m_adoConn.ExecuteSQL(vSQL);
	AfxMessageBox("修改密码成功");
	m_adoConn.ExitConnect();
	CDialog::OnOK();
}
