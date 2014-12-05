#if !defined(AFX_USERINFODLG_H__54BE1E5B_7BDF_468F_B679_C5E6100EE52C__INCLUDED_)
#define AFX_USERINFODLG_H__54BE1E5B_7BDF_468F_B679_C5E6100EE52C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// UserInfoDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CUserInfoDlg dialog

class CUserInfoDlg : public CDialog
{
// Construction
public:
	CUserInfoDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CUserInfoDlg)
	enum { IDD = IDD_USERINFO };
	CString	m_City;
	CString	m_Street;
	CString	m_UserName;
	CString	m_Telephone;
	CString	m_BranchCity;
	CString	m_AccountNum;
	CString	m_BranchName;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CUserInfoDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CUserInfoDlg)
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_USERINFODLG_H__54BE1E5B_7BDF_468F_B679_C5E6100EE52C__INCLUDED_)
