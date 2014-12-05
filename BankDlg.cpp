// BankDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Bank.h"
#include "BankDlg.h"
#include "ADOConn.h"
#include "ChangPswd.h"
#include "UserInfoDlg.h"
#include "LoginDlg.h"
#include "AmountDlg.h"
#include "TakeMoneyDlg.h"
#include "TransforDlg.h"
#include "DetailDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CBankDlg dialog
extern CString g_CustomerID;
extern CLoginDlg dlgLogin; //登陆框
CBankDlg::CBankDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CBankDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CBankDlg)
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
//	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	m_hIcon = AfxGetApp()->LoadIcon(IDB_BITMAP);
}

void CBankDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CBankDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CBankDlg, CDialog)
	//{{AFX_MSG_MAP(CBankDlg)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_CHANGEPSWD, OnChangepswd)
	ON_BN_CLICKED(IDC_USERINFO, OnUserinfo)
	ON_BN_CLICKED(IDC_SAVING, OnSaving)
	ON_BN_CLICKED(IDC_ACCOUNT, OnAccount)
	ON_BN_CLICKED(IDC_TAKING, OnTaking)
	ON_BN_CLICKED(IDC_TRANSFOR, OnTransfor)
	ON_BN_CLICKED(IDC_DETAIL, OnDetail)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CBankDlg message handlers

BOOL CBankDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here
	return TRUE;  // return TRUE  unless you set the focus to a control
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CBankDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
	//	CDialog::OnPaint();
		CPaintDC   dc(this); 
        CRect   rect; 
        GetClientRect(&rect); 
        CDC   dcMem; 
        dcMem.CreateCompatibleDC(&dc); 
        CBitmap   bmpBackground; 
        bmpBackground.LoadBitmap(IDB_BITMAP5); 
                //IDB_BITMAP是你自己的图对应的ID 
        BITMAP   bitmap; 
        bmpBackground.GetBitmap(&bitmap); 
        CBitmap   *pbmpOld=dcMem.SelectObject(&bmpBackground); 
        dc.StretchBlt(0,0,rect.Width(),rect.Height(),&dcMem,0,0,\
			bitmap.bmWidth,bitmap.bmHeight,SRCCOPY); 
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CBankDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CBankDlg::OnChangepswd() 
{
	// TODO: Add your control notification handler code here
	CChangPswd chdlg;
	chdlg.DoModal();
	delete chdlg;
}

void CBankDlg::OnUserinfo() 
{
	// TODO: Add your control notification handler code here
	CUserInfoDlg dlg;
	dlg.DoModal();
	delete dlg;
}

void CBankDlg::OnCancel() 
{
	// TODO: Add extra cleanup here
	if(MessageBox("确实要退出系统吗？","退出提示",MB_YESNO|MB_ICONQUESTION)==IDYES)
	{
		CDialog::OnCancel();
		CLoginDlg dlg;
		dlg.DoModal();
	}
}


void CBankDlg::OnSaving() 
{
	// TODO: Add your control notification handler code here
	CAmountDlg dlg;
	dlg.DoModal();
}

void CBankDlg::OnAccount() 
{
	// TODO: Add your control notification handler code here
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
	CString str;
	str.Format("您的账户余额为:%2f",balance);
	AfxMessageBox(str);
}

void CBankDlg::OnTaking() 
{
	// TODO: Add your control notification handler code here
	CTakeMoneyDlg dlg;
	dlg.DoModal();
}

void CBankDlg::OnTransfor() 
{
	// TODO: Add your control notification handler code here
	CTransforDlg dlg;
	dlg.DoModal();
}


void CBankDlg::OnDetail() 
{
	// TODO: Add your control notification handler code here
	CDetailDlg dlg;
	dlg.DoModal();
}
