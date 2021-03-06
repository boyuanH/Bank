#if !defined(AFX_LOGINDLG_H__33660EED_D1DB_42D7_A1F0_6558677FC916__INCLUDED_)
#define AFX_LOGINDLG_H__33660EED_D1DB_42D7_A1F0_6558677FC916__INCLUDED_

#include "ButtonST.h"	// Added by ClassView
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// LoginDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CLoginDlg dialog

//#include "CButtonST.h"

class CLoginDlg : public CDialog
{
// Construction
public:
	CButtonST m_btn;
	CLoginDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CLoginDlg)
	enum { IDD = IDD_LOGIN_DIALOG };
	CString	m_Password;
	int		m_UserType;
	CString	m_UserID;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CLoginDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CLoginDlg)
	virtual void OnOK();
	afx_msg void OnRadioCustomer();
	afx_msg void OnRadioEmployee();
	virtual BOOL OnInitDialog();
	afx_msg void OnButtonRegist();
	virtual void OnCancel();
	afx_msg void OnRadio1();
	afx_msg void OnPaint();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	int m_iLoginCount;
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_LOGINDLG_H__33660EED_D1DB_42D7_A1F0_6558677FC916__INCLUDED_)
