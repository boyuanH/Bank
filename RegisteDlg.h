#if !defined(AFX_REGISTEDLG_H__4F752207_3608_41A8_A5EC_91FBED1D99FE__INCLUDED_)
#define AFX_REGISTEDLG_H__4F752207_3608_41A8_A5EC_91FBED1D99FE__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// RegisteDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CRegisteDlg dialog

class CRegisteDlg : public CDialog
{
// Construction
public:
	int CheckCustomerID(CString m_UserID);
	double QueryBalance();
	void EmptyEdit();
	void InsertUserInfo();
	int CheckUserID(CString m_UserID);
	CRegisteDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CRegisteDlg)
	enum { IDD = IDD_REGIST_DIALOG };
	CString	m_UserID;
	CString	m_City;
	CString	m_Street;
	CString	m_UserName;
	CString	m_Telephone;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CRegisteDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CRegisteDlg)
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_REGISTEDLG_H__4F752207_3608_41A8_A5EC_91FBED1D99FE__INCLUDED_)
