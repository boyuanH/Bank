// Bank.h : main header file for the BANK application
//

#if !defined(AFX_BANK_H__0EC1BF29_78C1_4E78_AC39_6383FFB3434A__INCLUDED_)
#define AFX_BANK_H__0EC1BF29_78C1_4E78_AC39_6383FFB3434A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CBankApp:
// See Bank.cpp for the implementation of this class
//

class CBankApp : public CWinApp
{
public:
	CBankApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CBankApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CBankApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_BANK_H__0EC1BF29_78C1_4E78_AC39_6383FFB3434A__INCLUDED_)
