// ModEmpDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Bank.h"
#include "ModEmpDlg.h"
#include "ADOConn.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CModEmpDlg dialog


CModEmpDlg::CModEmpDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CModEmpDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CModEmpDlg)
	m_EmployeeDate = _T("");
	m_EmployeeID = _T("");
	m_EmployeeName = _T("");
	m_EmployeeTel = _T("");
	//}}AFX_DATA_INIT
}


void CModEmpDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CModEmpDlg)
	DDX_Text(pDX, IDC_EMPLOYEEDATE, m_EmployeeDate);
	DDX_Text(pDX, IDC_EMPLOYEEID, m_EmployeeID);
	DDX_Text(pDX, IDC_EMPLOYEENAME, m_EmployeeName);
	DDX_Text(pDX, IDC_EMPLOYEETEL, m_EmployeeTel);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CModEmpDlg, CDialog)
	//{{AFX_MSG_MAP(CModEmpDlg)
	ON_BN_CLICKED(IDC_BUTTONMOD, OnButtonmod)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CModEmpDlg message handlers

void CModEmpDlg::OnOK() 
{
	// TODO: Add extra validation here
	UpdateData();
//	if(m_EmployeeID=="")
//	{
//		AfxMessageBox("请输入要修改的雇员号");
//		return;
//	}
	CADOConn m_ADOConn;
	m_ADOConn.OnInitADOConn(); //打开数据库连接
	_RecordsetPtr m_pRecordset;//定义记录集指针
	_bstr_t empSQL="Select * from employee where employee_id='"+m_EmployeeID+"'";
	m_pRecordset=m_ADOConn.GetRecordset(empSQL);
	if(m_pRecordset->adoEOF) //入股记录集是空的
	{
		MessageBox("账号不存在,无法修改");
		GetDlgItem(IDC_EMPLOYEEID)->SetWindowText("");
		return;
	}
	GetDlgItem(IDC_EMPLOYEEID)->EnableWindow(false);
	GetDlgItem(IDC_EMPLOYEENAME)->EnableWindow(true);
	GetDlgItem(IDC_EMPLOYEETEL)->EnableWindow(true);
	GetDlgItem(IDC_EMPLOYEEDATE)->EnableWindow(true);
	AfxMessageBox("请输入新的信息！");
}

BOOL CModEmpDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	GetDlgItem(IDC_EMPLOYEENAME)->EnableWindow(false);
	GetDlgItem(IDC_EMPLOYEETEL)->EnableWindow(false);
	GetDlgItem(IDC_EMPLOYEEDATE)->EnableWindow(false);
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CModEmpDlg::OnButtonmod() 
{
	// TODO: Add your control notification handler code here
	UpdateData();
	CADOConn m_ADOConn;
	m_ADOConn.OnInitADOConn(); //打开数据库连接
	_bstr_t vSQL="update employee set employee_name='"+m_EmployeeName+"',employee_tel\
		='"+m_EmployeeTel+"',start_date='"+m_EmployeeDate+"'\
		where employee_id='"+m_EmployeeID+"'";
	m_ADOConn.ExecuteSQL(vSQL);
	AfxMessageBox("修改成功！");
	CDialog::OnOK();
}
