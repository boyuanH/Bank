// Bank.cpp : Defines the class behaviors for the application.
//

#include "stdafx.h"
#include "Bank.h"
#include "BankDlg.h"
#include "LoginDlg.h"
#include "EmployeeDlg.h"
#include "MangerDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CBankApp

BEGIN_MESSAGE_MAP(CBankApp, CWinApp)
	//{{AFX_MSG_MAP(CBankApp)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG
	ON_COMMAND(ID_HELP, CWinApp::OnHelp)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CBankApp construction

CBankApp::CBankApp()
{
	// TODO: add construction code here,
	// Place all significant initialization in InitInstance
}

/////////////////////////////////////////////////////////////////////////////
// The one and only CBankApp object

CBankApp theApp;
CLoginDlg dlgLogin; //登陆框
CString g_CustomerID;//全局变量，保存用户id
int g_UserType;  //全局变量，保存用户类型

/////////////////////////////////////////////////////////////////////////////
// CBankApp initialization

BOOL CBankApp::InitInstance()
{
	AfxEnableControlContainer();

	// Standard initialization
	// If you are not using these features and wish to reduce the size
	//  of your final executable, you should remove from the following
	//  the specific initialization routines you do not need.

#ifdef _AFXDLL
	Enable3dControls();			// Call this when using MFC in a shared DLL
#else
	Enable3dControlsStatic();	// Call this when linking to MFC statically
#endif
	
/*	CBankDlg dlg;
	CLoginDlg dlgLogin;
	m_pMainWnd = &dlg;
	int nResponse = dlg.DoModal();
	if (nResponse == IDOK)
	{
		// TODO: Place code here to handle when the dialog is
		//  dismissed with OK
		CBankDlg *pdlg=new CBankDlg;
		m_pMainWnd=pdlg;
		pdlg->DoModal();
		delete pdlg;
		pdlg=NULL;
	}
	else if (nResponse == IDCANCEL)
	{
		// TODO: Place code here to handle when the dialog is
		//  dismissed with Cancel
	}*/

	// Since the dialog has been closed, return FALSE so that we exit the
	//  application, rather than start the application's message pump.

	dlgLogin.DoModal();
	  return FALSE;
}
