// DetailDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Bank.h"
#include "DetailDlg.h"
#include "ADOConn.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDetailDlg dialog

extern CString g_CustomerID;

CDetailDlg::CDetailDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CDetailDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDetailDlg)
	//}}AFX_DATA_INIT
}


void CDetailDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDetailDlg)
	DDX_Control(pDX, IDC_LIST1, m_ListDetail);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDetailDlg, CDialog)
	//{{AFX_MSG_MAP(CDetailDlg)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDetailDlg message handlers

BOOL CDetailDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	/*********************设置列表框的风格***********************************************/
	DWORD dwExStyle=LVS_EX_FULLROWSELECT|LVS_EX_GRIDLINES|LVS_EX_HEADERDRAGDROP|\
		LVS_EX_ONECLICKACTIVATE;
	m_ListDetail.ModifyStyle(0,LVS_REPORT|LVS_SINGLESEL|LVS_SHOWSELALWAYS);
	m_ListDetail.SetExtendedStyle(dwExStyle);
	m_ListDetail.InsertColumn(0,"账号",LVCFMT_CENTER,100,0);
	m_ListDetail.InsertColumn(1,"交易时间",	LVCFMT_CENTER,250,0);
	m_ListDetail.InsertColumn(2,"交易类型",LVCFMT_CENTER,90,0);
	m_ListDetail.InsertColumn(3,"交易金额",LVCFMT_CENTER,90,0);
	/*************************检索出本账号的交易记录*************************************/
	ListAll();
	UpdateData(false);
	return TRUE;
		// EXCEPTION: OCX Property Pages should return FALSE
}

void CDetailDlg::ListAll()
{
	CADOConn m_ADOConn;
	_bstr_t vSQL="select * from depositor\
		where account_number='"+g_CustomerID+"'";
	_RecordsetPtr m_pRecordset;
	m_ADOConn.OnInitADOConn();
	m_pRecordset=m_ADOConn.GetRecordset(vSQL);
	m_ListDetail.DeleteAllItems();//清空列表
	m_pRecordset->MoveFirst();//移动到第一条记录
	CString date,type,amount;
	int index=0;
	/**********************获取数据***************/
	while(!m_pRecordset->adoEOF)
	{
		date=(LPCTSTR)(_bstr_t)m_pRecordset->GetCollect("access_date");
		type=(LPCTSTR)(_bstr_t)m_pRecordset->GetCollect("account_type");
		amount=(LPCTSTR)(_bstr_t)m_pRecordset->GetCollect("amount");

		m_ListDetail.InsertItem(index,g_CustomerID);//向列表插入此项
		m_ListDetail.SetItemText(index,0,g_CustomerID);
		m_ListDetail.SetItemText(index,1,date);
		m_ListDetail.SetItemText(index,2,type);
		m_ListDetail.SetItemText(index,3,amount);
		//后移记录，行数加1
		m_pRecordset->MoveNext();
		index++;
	}
	m_ADOConn.ExitConnect();
	return;
}

