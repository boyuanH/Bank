// EmployeeDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Bank.h"
#include "EmployeeDlg.h"
#include "AddUserDlg.h"
#include "BranchDlg.h"
#include "DelUserDlg.h"
#include "LoginDlg.h"
#include "LoanDlg.h"
#include "AllAccountDlg.h"
#include "ALlLoanDlg.h"
#include "PaymentDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CEmployeeDlg dialog

extern CLoginDlg dlgLogin; //登陆框
extern CString g_CustomerID;

CEmployeeDlg::CEmployeeDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CEmployeeDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CEmployeeDlg)
	//}}AFX_DATA_INIT
}


void CEmployeeDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CEmployeeDlg)
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CEmployeeDlg, CDialog)
	//{{AFX_MSG_MAP(CEmployeeDlg)
	ON_BN_CLICKED(IDC_ADDUSER, OnAdduser)
	ON_BN_CLICKED(IDC_BANKINFO, OnBankinfo)
	ON_BN_CLICKED(IDC_DELETEUSER, OnDeleteuser)
	ON_BN_CLICKED(IDC_LOAN, OnLoan)
	ON_BN_CLICKED(IDC_ALLACCOUNT, OnAllaccount)
	ON_BN_CLICKED(IDC_ALLLOAN, OnAllloan)
	ON_BN_CLICKED(IDC_PAYMENT, OnPayment)
	ON_WM_PAINT()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CEmployeeDlg message handlers

void CEmployeeDlg::OnAdduser() 
{
	// TODO: Add your control notification handler code here
	CAddUserDlg dlg;
	dlg.DoModal();
}

void CEmployeeDlg::OnBankinfo() 
{
	// TODO: Add your control notification handler code here
	CBranchDlg dlg;
	dlg.DoModal();
}

void CEmployeeDlg::OnDeleteuser() 
{
	// TODO: Add your control notification handler code here
	CDelUserDlg dlg;
	dlg.DoModal();
}

void CEmployeeDlg::OnCancel() 
{
	// TODO: Add extra cleanup here
	if(MessageBox("确实要退出系统吗？","退出提示",MB_YESNO|MB_ICONQUESTION)==IDYES)
	{
		CDialog::OnCancel();
		CLoginDlg dlg;
		dlg.DoModal();
	}
}

void CEmployeeDlg::OnLoan() 
{
	// TODO: Add your control notification handler code here
	CLoanDlg dlg;
	dlg.DoModal();
}

void CEmployeeDlg::OnAllaccount() 
{
	// TODO: Add your control notification handler code here
	CAllAccountDlg dlg;
	dlg.DoModal();
}

void CEmployeeDlg::OnAllloan() 
{
	// TODO: Add your control notification handler code here
	CAllLoanDlg dlg;
	dlg.DoModal();
}

void CEmployeeDlg::OnPayment() 
{
	// TODO: Add your control notification handler code here
	CPaymentDlg dlg;
	dlg.DoModal();
}

void CEmployeeDlg::OnPaint() 
{
	CPaintDC dc(this); // device context for painting
	
	// TODO: Add your message handler code here 
	CRect   rect; 
	GetClientRect(&rect); 
	CDC   dcMem; 
	dcMem.CreateCompatibleDC(&dc); 
	CBitmap   bmpBackground; 
	bmpBackground.LoadBitmap(IDB_BITMAP3); 
	//IDB_BITMAP是你自己的图对应的ID 
	BITMAP   bitmap; 
	bmpBackground.GetBitmap(&bitmap); 
	CBitmap   *pbmpOld=dcMem.SelectObject(&bmpBackground); 
	dc.StretchBlt(0,0,rect.Width(),rect.Height(),&dcMem,0,0,\
		bitmap.bmWidth,bitmap.bmHeight,SRCCOPY); 
	// Do not call CDialog::OnPaint() for painting messages
}

BOOL CEmployeeDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	GetDlgItem(IDC_EMPLOYEEID)->SetWindowText(g_CustomerID);
	GetDlgItem(IDC_EMPLOYEEID)->EnableWindow(false);
	UpdateData(false);
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}


