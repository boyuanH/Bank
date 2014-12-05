#if !defined(AFX_ADDUSERDLG_H__0C646731_B992_4993_90CC_0B99B06B3BA5__INCLUDED_)
#define AFX_ADDUSERDLG_H__0C646731_B992_4993_90CC_0B99B06B3BA5__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// AddUserDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CAddUserDlg dialog

class CAddUserDlg : public CDialog
{
// Construction
public:
	int CheckBranch();
	void InsertAccountNum();
	int CheckAccountNum();
	CAddUserDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CAddUserDlg)
	enum { IDD = IDD_ADDUSERDIALOG };
	CString	m_AccountNum;
	double	m_Amount;
	CString	m_CustomerID;
	CString	m_Password;
	CString	m_Password2;
	CString	m_BranchName;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAddUserDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CAddUserDlg)
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ADDUSERDLG_H__0C646731_B992_4993_90CC_0B99B06B3BA5__INCLUDED_)
