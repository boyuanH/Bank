// DelUserDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Bank.h"
#include "DelUserDlg.h"
#include "ADOConn.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDelUserDlg dialog


CDelUserDlg::CDelUserDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CDelUserDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDelUserDlg)
	m_AccountNum = _T("");
	//}}AFX_DATA_INIT
}


void CDelUserDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDelUserDlg)
	DDX_Text(pDX, IDC_ACCOUNTNUM, m_AccountNum);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDelUserDlg, CDialog)
	//{{AFX_MSG_MAP(CDelUserDlg)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDelUserDlg message handlers

void CDelUserDlg::OnOK() 
{
	// TODO: Add extra validation here
	UpdateData();
	if(!CheckAccountNum())
	{
		AfxMessageBox("该账户不存在");
		GetDlgItem(IDC_ACCOUNTNUM)->SetWindowText("");
		return;
	}
	if(MessageBox("确认要注销该账号吗？注销将删除该账号所有交易记录","警告",MB_YESNO)==IDYES)
	{
		DeleteAccount();
		AfxMessageBox("成功注销该用户");
	}
	CDialog::OnOK();
}

int CDelUserDlg::CheckAccountNum()
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

void CDelUserDlg::DeleteAccount()
{
	_bstr_t dSQL,vSQL;
	dSQL="delete from depositor where account_number='"+m_AccountNum+"'";
	vSQL="delete from account where account_number='"+m_AccountNum+"'";
	CADOConn m_ADOConn;
	_RecordsetPtr m_Recordset;
	m_ADOConn.OnInitADOConn();
	m_ADOConn.ExecuteSQL(dSQL);
	m_ADOConn.ExecuteSQL(vSQL);
	m_ADOConn.ExitConnect();
}
