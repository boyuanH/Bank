// RegisteDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Bank.h"
#include "RegisteDlg.h"
#include "ADOConn.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CRegisteDlg dialog

extern CString g_CustomerID;

CRegisteDlg::CRegisteDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CRegisteDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CRegisteDlg)
	m_UserID = _T("");
	m_City = _T("");
	m_Street = _T("");
	m_UserName = _T("");
	m_Telephone = _T("");
	//}}AFX_DATA_INIT
}


void CRegisteDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CRegisteDlg)
	DDX_Text(pDX, IDC_USERID, m_UserID);
	DDX_Text(pDX, IDC_CITY, m_City);
	DDX_Text(pDX, IDC_STREET, m_Street);
	DDX_Text(pDX, IDC_USERNAME, m_UserName);
	DDX_Text(pDX, IDC_TELEPHONE, m_Telephone);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CRegisteDlg, CDialog)
	//{{AFX_MSG_MAP(CRegisteDlg)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CRegisteDlg message handlers

void CRegisteDlg::OnOK() 
{
	// TODO: Add extra validation here
	//注册用户，先检查用户ID是否存在
	//判断两次密码输入是否一致，且输入不能为空
	//将输入的数据插入数据库Customer表中
	BOOL bLogOn=FALSE;
	UpdateData(true);
	if(m_UserID==""||m_Telephone==""||m_UserName==""||m_City==""||m_Street=="")
	{
		AfxMessageBox("输入的信息不完整，请继续输入");
		return;
	}
	if(CheckUserID(m_UserID)==0)
	{
		AfxMessageBox("该客户ID已经被注册，请重新输入");
		EmptyEdit();
		return;
	}
	InsertUserInfo();
	AfxMessageBox("用户注册成功");
	CDialog::OnOK();
}

int CRegisteDlg::CheckUserID(CString m_UserID)
{
	//先检查账户是否存在，空返回1
	_bstr_t vSQL="Select * from account where account_number='"+m_UserID+"'";
	CADOConn m_ADOConn;
	m_ADOConn.OnInitADOConn(); //打开数据库连接
	_RecordsetPtr m_pRecordset;//定义记录集指针
	m_pRecordset=m_ADOConn.GetRecordset(vSQL);
	if(m_pRecordset->adoEOF) //入股记录集是空的,表示没有被注册，空返回1
		return 1;
	else
		return 0;//被注册，非空返回0
}

void CRegisteDlg::InsertUserInfo()
{//添加用户信息
	_bstr_t vSQL="Insert into customer(customer_id,customer_name,customer_street,customer_city,\
		customer_tel) values('"+m_UserID+"','"+m_UserName+"','"+m_Street+"','"+m_City+"',\
		'"+m_Telephone+"')";
	CADOConn m_ADOConn;
	m_ADOConn.OnInitADOConn(); //打开数据库连接
	m_ADOConn.ExecuteSQL(vSQL);//执行插入语句
	m_ADOConn.ExitConnect();//断开数据源连接
}

void CRegisteDlg::EmptyEdit()
{
	GetDlgItem(IDC_USERID)->SetWindowText("");
	GetDlgItem(IDC_TELEPHONE)->SetWindowText("");
	GetDlgItem(IDC_USERNAME)->SetWindowText("");
	GetDlgItem(IDC_STREET)->SetWindowText("");
	GetDlgItem(IDC_CITY)->SetWindowText("");
}

double CRegisteDlg::QueryBalance()
{
	_bstr_t vSQL="select balance from account where account_number='"+g_CustomerID+"'";
	CADOConn m_ADOConn;
	m_ADOConn.OnInitADOConn();
	_RecordsetPtr m_pRecordset;
	m_pRecordset=m_ADOConn.GetRecordset(vSQL);
	double balance;
	CString strBalance;
	_variant_t theValue;
	theValue=m_pRecordset->GetCollect("balance");
	if(theValue.vt!=VT_NULL)
		strBalance=(char *)_bstr_t(theValue);
	balance=atof(strBalance);
	return balance;
}

int CRegisteDlg::CheckCustomerID(CString m_UserID)
{
	//先检查客户是否存在，空返回1
	_bstr_t vSQL="Select * from customer where customer_id='"+m_UserID+"'";
	CADOConn m_ADOConn;
	m_ADOConn.OnInitADOConn(); //打开数据库连接
	_RecordsetPtr m_pRecordset;//定义记录集指针
	m_pRecordset=m_ADOConn.GetRecordset(vSQL);
	if(m_pRecordset->adoEOF) //入股记录集是空的,表示没有被注册，空返回1
		return 1;
	else
		return 0;//被注册，非空返回0
}
