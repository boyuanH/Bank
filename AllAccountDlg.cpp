// AllAccountDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Bank.h"
#include "AllAccountDlg.h"
#include "ADOConn.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAllAccountDlg dialog


CAllAccountDlg::CAllAccountDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CAllAccountDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CAllAccountDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CAllAccountDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAllAccountDlg)
	DDX_Control(pDX, IDC_LIST1, m_ListAccount);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CAllAccountDlg, CDialog)
	//{{AFX_MSG_MAP(CAllAccountDlg)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CAllAccountDlg message handlers

BOOL CAllAccountDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	DWORD dwExStyle=LVS_EX_FULLROWSELECT|LVS_EX_GRIDLINES|LVS_EX_HEADERDRAGDROP|\
		LVS_EX_ONECLICKACTIVATE;
	m_ListAccount.ModifyStyle(0,LVS_REPORT|LVS_SINGLESEL|LVS_SHOWSELALWAYS);
	m_ListAccount.SetExtendedStyle(dwExStyle);
	m_ListAccount.InsertColumn(0,"账号",LVCFMT_CENTER,100,0);
	m_ListAccount.InsertColumn(1,"所在银行",	LVCFMT_CENTER,100,0);
	m_ListAccount.InsertColumn(2,"客户ID",LVCFMT_CENTER,100,0);
	m_ListAccount.InsertColumn(3,"客户姓名",LVCFMT_CENTER,100,0);
	m_ListAccount.InsertColumn(4,"账户余额",	LVCFMT_CENTER,100,0);
	ListAll();
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CAllAccountDlg::ListAll()
{
	CADOConn m_ADOConn;
	_bstr_t vSQL="select distinct D.account_number,D.customer_id,C.customer_name,A.balance,A.branch_name\
		from account as A,depositor as D,customer as C where A.account_number=D.account_number\
		and C.customer_id=D.customer_id";
	_RecordsetPtr m_pRecordset;
	m_ADOConn.OnInitADOConn();
	m_pRecordset=m_ADOConn.GetRecordset(vSQL);
	if(m_pRecordset->adoEOF) //入股记录集是空的
		return;
	m_ListAccount.DeleteAllItems();//清空列表
	m_pRecordset->MoveFirst();//移动到第一条记录
	CString num,id,name,balance,branch;
	int index=0;
	/**********************获取数据***************/
	while(!m_pRecordset->adoEOF)
	{
		num=(LPCTSTR)(_bstr_t)m_pRecordset->GetCollect("account_number");
		id=(LPCTSTR)(_bstr_t)m_pRecordset->GetCollect("customer_id");
		name=(LPCTSTR)(_bstr_t)m_pRecordset->GetCollect("customer_name");
		balance=(LPCTSTR)(_bstr_t)m_pRecordset->GetCollect("balance");
		branch=(LPCTSTR)(_bstr_t)m_pRecordset->GetCollect("branch_name");

		m_ListAccount.InsertItem(index,num);//向列表插入此项
		m_ListAccount.SetItemText(index,1,branch);
		m_ListAccount.SetItemText(index,2,id);
		m_ListAccount.SetItemText(index,3,name);
		m_ListAccount.SetItemText(index,4,balance);
		//后移记录，行数加1
		m_pRecordset->MoveNext();
		index++;
	}
	m_ADOConn.ExitConnect();
	return;
}
