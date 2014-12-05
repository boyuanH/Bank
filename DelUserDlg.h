#if !defined(AFX_DELUSERDLG_H__100F4A25_0253_41C6_88C2_BA013E55D36B__INCLUDED_)
#define AFX_DELUSERDLG_H__100F4A25_0253_41C6_88C2_BA013E55D36B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DelUserDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDelUserDlg dialog

class CDelUserDlg : public CDialog
{
// Construction
public:
	void DeleteAccount();
	int CheckAccountNum();
	CDelUserDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CDelUserDlg)
	enum { IDD = IDD_DELUSERDIALOG };
	CString	m_AccountNum;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDelUserDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDelUserDlg)
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DELUSERDLG_H__100F4A25_0253_41C6_88C2_BA013E55D36B__INCLUDED_)
