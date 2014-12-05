// UserInfoDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Bank.h"
#include "UserInfoDlg.h"
#include "ADOConn.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CUserInfoDlg dialog

extern CString g_CustomerID;

CUserInfoDlg::CUserInfoDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CUserInfoDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CUserInfoDlg)
	m_City = _T("");
	m_Street = _T("");
	m_UserName = _T("");
	m_Telephone = _T("");
	m_BranchCity = _T("");
	m_AccountNum = _T("");
	m_BranchName = _T("");
	//}}AFX_DATA_INIT
}


void CUserInfoDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CUserInfoDlg)
	DDX_Text(pDX, IDC_CITY, m_City);
	DDX_Text(pDX, IDC_STREET, m_Street);
	DDX_Text(pDX, IDC_USERNAME, m_UserName);
	DDX_Text(pDX, IDC_TELEPHONE, m_Telephone);
	DDX_Text(pDX, IDC_BRANCHCITY, m_BranchCity);
	DDX_Text(pDX, IDC_ACCOUNTNUM, m_AccountNum);
	DDX_Text(pDX, IDC_BRANCHNAME, m_BranchName);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CUserInfoDlg, CDialog)
	//{{AFX_MSG_MAP(CUserInfoDlg)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CUserInfoDlg message handlers

BOOL CUserInfoDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	//设置编辑框不可输入
	GetDlgItem(IDC_ACCOUNTNUM)->EnableWindow(false);
	GetDlgItem(IDC_USERNAME)->EnableWindow(false);
	GetDlgItem(IDC_CITY)->EnableWindow(false);
	GetDlgItem(IDC_STREET)->EnableWindow(false);
	GetDlgItem(IDC_TELEPHONE)->EnableWindow(false);
	GetDlgItem(IDC_BRANCHNAME)->EnableWindow(false);
	GetDlgItem(IDC_BRANCHCITY)->EnableWindow(false);
	//查询三个表
	_bstr_t vSQL="select C.customer_name,C.customer_street,C.customer_city,C.customer_tel,\
		B.branch_name,B.branch_city\
		from customer as C,account as A,depositor as D,branch as B\
		where A.branch_name=B.branch_name and D.account_number=A.account_number and\
		D.customer_id=C.customer_id and A.account_number='"+g_CustomerID+"'";
	//连接数据库操作
	CADOConn m_ADOConn;
	m_ADOConn.OnInitADOConn();
	_RecordsetPtr m_pRecordset;
	m_pRecordset=m_ADOConn.GetRecordset(vSQL);
	//定义变量保存数据
	_variant_t theValue;
	//转换为字符型
	m_AccountNum=g_CustomerID;
	theValue=(_bstr_t)m_pRecordset->GetCollect("customer_name");
	if(theValue.vt!=VT_NULL)
		m_UserName=(char *)_bstr_t(theValue);
	theValue=m_pRecordset->GetCollect("customer_street");
	if(theValue.vt!=VT_NULL)
		m_Street=(char *)_bstr_t(theValue);
	theValue=m_pRecordset->GetCollect("customer_city");
	if(theValue.vt!=VT_NULL)
		m_City=(char *)_bstr_t(theValue);

	theValue=m_pRecordset->GetCollect("customer_tel");
	if(theValue.vt!=VT_NULL)
		m_Telephone=(char *)_bstr_t(theValue);
	theValue=m_pRecordset->GetCollect("branch_name");
	if(theValue.vt!=VT_NULL)
		m_BranchName=(char *)_bstr_t(theValue); 
	theValue=m_pRecordset->GetCollect("branch_city");
	if(theValue.vt!=VT_NULL)
		m_BranchCity=(char *)_bstr_t(theValue);

	UpdateData(false);
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}
