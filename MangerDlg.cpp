// MangerDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Bank.h"
#include "MangerDlg.h"
#include "AddEmpDlg.h"
#include "LoginDlg.h"
#include "AllEmpDlg.h"
#include "DelEmpDlg.h"
#include "ModEmpDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMangerDlg dialog

extern CLoginDlg dlgLogin; //登陆框
CMangerDlg::CMangerDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CMangerDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CMangerDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CMangerDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CMangerDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CMangerDlg, CDialog)
	//{{AFX_MSG_MAP(CMangerDlg)
	ON_BN_CLICKED(IDC_ADDEMPLOYEE, OnAddemployee)
	ON_BN_CLICKED(IDC_ALLEMPLOYEE, OnAllemployee)
	ON_WM_PAINT()
	ON_BN_CLICKED(IDC_DELETEEMPLOYEE, OnDeleteemployee)
	ON_BN_CLICKED(IDC_MODIFYEMPLOYEE, OnModifyemployee)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMangerDlg message handlers

void CMangerDlg::OnAddemployee() 
{
	// TODO: Add your control notification handler code here
	CAddEmpDlg dlg;
	dlg.DoModal();
}

void CMangerDlg::OnCancel() 
{
	// TODO: Add extra cleanup here
	if(MessageBox("确实要退出系统吗？","退出提示",MB_YESNO|MB_ICONQUESTION)==IDYES)
	{
		CDialog::OnCancel();
		CLoginDlg dlg;
		dlg.DoModal();
	}
}

void CMangerDlg::OnAllemployee() 
{
	// TODO: Add your control notification handler code here
	CAllEmpDlg dlg;
	dlg.DoModal();
}

void CMangerDlg::OnPaint() 
{
	CPaintDC dc(this); // device context for painting
	
	// TODO: Add your message handler code here
	
	CRect   rect; 
	GetClientRect(&rect); 
	CDC   dcMem; 
	dcMem.CreateCompatibleDC(&dc); 
	CBitmap   bmpBackground; 
	bmpBackground.LoadBitmap(IDB_BITMAP2); 
	//IDB_BITMAP是你自己的图对应的ID 
	BITMAP   bitmap; 
	bmpBackground.GetBitmap(&bitmap); 
	CBitmap   *pbmpOld=dcMem.SelectObject(&bmpBackground); 
	dc.StretchBlt(0,0,rect.Width(),rect.Height(),&dcMem,0,0,\
		bitmap.bmWidth,bitmap.bmHeight,SRCCOPY); 
	// Do not call CDialog::OnPaint() for painting messages
}

void CMangerDlg::OnDeleteemployee() 
{
	// TODO: Add your control notification handler code here
	CDelEmpDlg dlg;
	dlg.DoModal();
}

void CMangerDlg::OnModifyemployee() 
{
	// TODO: Add your control notification handler code here
	CModEmpDlg dlg;
	dlg.DoModal();
}
