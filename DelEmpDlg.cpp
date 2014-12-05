// DelEmpDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Bank.h"
#include "DelEmpDlg.h"
#include "ADOConn.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDelEmpDlg dialog


CDelEmpDlg::CDelEmpDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CDelEmpDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDelEmpDlg)
	m_EmployeeID = _T("");
	//}}AFX_DATA_INIT
}


void CDelEmpDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDelEmpDlg)
	DDX_Text(pDX, IDC_EMPLOYEEID, m_EmployeeID);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDelEmpDlg, CDialog)
	//{{AFX_MSG_MAP(CDelEmpDlg)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDelEmpDlg message handlers

void CDelEmpDlg::OnOK() 
{
	// TODO: Add extra validation here
	UpdateData();
	CADOConn m_ADOConn;
	m_ADOConn.OnInitADOConn(); //打开数据库连接
	_RecordsetPtr m_pRecordset;//定义记录集指针
	_bstr_t empSQL="Select * from employee where employee_id='"+m_EmployeeID+"'";
	m_pRecordset=m_ADOConn.GetRecordset(empSQL);
	if(m_pRecordset->adoEOF) //入股记录集是空的
	{
		MessageBox("账号不存在");
		GetDlgItem(IDC_EMPLOYEEID)->SetWindowText("");
		return;
	}
	_bstr_t delSQL="delete from works_for where worker_employee_id='"+m_EmployeeID+"'";
	_bstr_t deldelSQL="delete from employee where employee_id='"+m_EmployeeID+"'";
	m_ADOConn.ExecuteSQL(delSQL);
	m_ADOConn.ExecuteSQL(deldelSQL);
	AfxMessageBox("删除成功！");
	CDialog::OnOK();
}
