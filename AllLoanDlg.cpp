// AllLoanDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Bank.h"
#include "AllLoanDlg.h"
#include "ADOConn.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAllLoanDlg dialog


CAllLoanDlg::CAllLoanDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CAllLoanDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CAllLoanDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CAllLoanDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAllLoanDlg)
	DDX_Control(pDX, IDC_LIST1, m_ListLoan);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CAllLoanDlg, CDialog)
	//{{AFX_MSG_MAP(CAllLoanDlg)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CAllLoanDlg message handlers

BOOL CAllLoanDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	DWORD dwExStyle=LVS_EX_FULLROWSELECT|LVS_EX_GRIDLINES|LVS_EX_HEADERDRAGDROP|\
		LVS_EX_ONECLICKACTIVATE;
	m_ListLoan.ModifyStyle(0,LVS_REPORT|LVS_SINGLESEL|LVS_SHOWSELALWAYS);
	m_ListLoan.SetExtendedStyle(dwExStyle);
	m_ListLoan.InsertColumn(0,"贷款号",LVCFMT_CENTER,100,0);
	m_ListLoan.InsertColumn(1,"所在银行",	LVCFMT_CENTER,100,0);
	m_ListLoan.InsertColumn(2,"客户ID",LVCFMT_CENTER,100,0);
	m_ListLoan.InsertColumn(3,"客户姓名",LVCFMT_CENTER,100,0);
	m_ListLoan.InsertColumn(4,"贷款额",	LVCFMT_CENTER,100,0);
	m_ListLoan.InsertColumn(5,"贷款日期",	LVCFMT_CENTER,100,0);
	ListAll();
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CAllLoanDlg::ListAll()
{
	CADOConn m_ADOConn;
	_bstr_t vSQL="select distinct L.loan_number,L.customer_id,C.customer_name,\
		L.branch_name,L.amount,L.loan_date from loan as L,customer as C where L.customer_id=C.customer_id";
	_RecordsetPtr m_pRecordset;
	m_ADOConn.OnInitADOConn();
	m_pRecordset=m_ADOConn.GetRecordset(vSQL);
	if(m_pRecordset->adoEOF) //入股记录集是空的
		return;
	m_ListLoan.DeleteAllItems();//清空列表
	m_pRecordset->MoveFirst();//移动到第一条记录
	CString num,branch,id,name,amount,date;
	int index=0;
	/**********************获取数据***************/
	while(!m_pRecordset->adoEOF)
	{
		num=(LPCTSTR)(_bstr_t)m_pRecordset->GetCollect("loan_number");
		branch=(LPCTSTR)(_bstr_t)m_pRecordset->GetCollect("branch_name");
		name=(LPCTSTR)(_bstr_t)m_pRecordset->GetCollect("customer_name");
		id=(LPCTSTR)(_bstr_t)m_pRecordset->GetCollect("customer_id");
		amount=(LPCTSTR)(_bstr_t)m_pRecordset->GetCollect("amount");
		date=(LPCTSTR)(_bstr_t)m_pRecordset->GetCollect("loan_date");

		m_ListLoan.InsertItem(index,num);//向列表插入此项
		m_ListLoan.SetItemText(index,1,branch);
		m_ListLoan.SetItemText(index,2,id);
		m_ListLoan.SetItemText(index,3,name);
		m_ListLoan.SetItemText(index,4,amount);
		m_ListLoan.SetItemText(index,5,date);
		//后移记录，行数加1
		m_pRecordset->MoveNext();
		index++;
	}
	m_ADOConn.ExitConnect();
	return;
}
