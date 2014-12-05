// AllEmpDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Bank.h"
#include "AllEmpDlg.h"
#include "ADOConn.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAllEmpDlg dialog


CAllEmpDlg::CAllEmpDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CAllEmpDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CAllEmpDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CAllEmpDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAllEmpDlg)
	DDX_Control(pDX, IDC_LIST1, m_ListAllEmp);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CAllEmpDlg, CDialog)
	//{{AFX_MSG_MAP(CAllEmpDlg)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CAllEmpDlg message handlers

BOOL CAllEmpDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	DWORD dwExStyle=LVS_EX_FULLROWSELECT|LVS_EX_GRIDLINES|LVS_EX_HEADERDRAGDROP|\
		LVS_EX_ONECLICKACTIVATE;
	m_ListAllEmp.ModifyStyle(0,LVS_REPORT|LVS_SINGLESEL|LVS_SHOWSELALWAYS);
	m_ListAllEmp.SetExtendedStyle(dwExStyle);
	m_ListAllEmp.InsertColumn(0,"雇员ID",LVCFMT_CENTER,100,0);
	m_ListAllEmp.InsertColumn(1,"雇员密码",	LVCFMT_CENTER,100,0);
	m_ListAllEmp.InsertColumn(2,"雇员姓名",LVCFMT_CENTER,100,0);
	m_ListAllEmp.InsertColumn(3,"联系方式",LVCFMT_CENTER,100,0);
	m_ListAllEmp.InsertColumn(4,"工作日期",	LVCFMT_CENTER,100,0);
	ListAll();
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CAllEmpDlg::ListAll()
{
	CADOConn m_ADOConn;
	_bstr_t vSQL="select * from employee";
	_RecordsetPtr m_pRecordset;
	m_ADOConn.OnInitADOConn();
	m_pRecordset=m_ADOConn.GetRecordset(vSQL);
	if(m_pRecordset->adoEOF) //入股记录集是空的
		return;
	m_ListAllEmp.DeleteAllItems();//清空列表
	m_pRecordset->MoveFirst();//移动到第一条记录
	CString id,pswd,name,tel,date;
	int index=0;
	/**********************获取数据***************/
	while(!m_pRecordset->adoEOF)
	{
		id=(LPCTSTR)(_bstr_t)m_pRecordset->GetCollect("employee_id");
		pswd=(LPCTSTR)(_bstr_t)m_pRecordset->GetCollect("employee_pswd");
		name=(LPCTSTR)(_bstr_t)m_pRecordset->GetCollect("employee_name");
		tel=(LPCTSTR)(_bstr_t)m_pRecordset->GetCollect("employee_tel");
		date=(LPCTSTR)(_bstr_t)m_pRecordset->GetCollect("start_date");

		m_ListAllEmp.InsertItem(index,id);//向列表插入此项
		m_ListAllEmp.SetItemText(index,1,pswd);
		m_ListAllEmp.SetItemText(index,2,name);
		m_ListAllEmp.SetItemText(index,3,tel);
		m_ListAllEmp.SetItemText(index,4,date);
		//后移记录，行数加1
		m_pRecordset->MoveNext();
		index++;
	}
	m_ADOConn.ExitConnect();
	return;
}
