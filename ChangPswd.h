#if !defined(AFX_CHANGPSWD_H__B13AB517_E16B_42EC_8F8F_B7C5E16EF6A6__INCLUDED_)
#define AFX_CHANGPSWD_H__B13AB517_E16B_42EC_8F8F_B7C5E16EF6A6__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ChangPswd.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CChangPswd dialog

class CChangPswd : public CDialog
{
// Construction
public:
	CChangPswd(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CChangPswd)
	enum { IDD = IDD_CHANGEPSWD };
	CString	m_NewPswd;
	CString	m_NewPswd2;
	CString	m_OldPswd;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CChangPswd)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CChangPswd)
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CHANGPSWD_H__B13AB517_E16B_42EC_8F8F_B7C5E16EF6A6__INCLUDED_)
