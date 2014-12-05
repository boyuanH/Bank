#if !defined(AFX_BRANCHDLG_H__77FBC419_4402_4086_89B2_F4BB6468F27C__INCLUDED_)
#define AFX_BRANCHDLG_H__77FBC419_4402_4086_89B2_F4BB6468F27C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// BranchDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CBranchDlg dialog

class CBranchDlg : public CDialog
{
// Construction
public:
	void RefreshData();
	void ListAll();
	CBranchDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CBranchDlg)
	enum { IDD = IDD_BRANCHDIALOG };
	CListCtrl	m_ListBranch;
	CString	m_Assets;
	CString	m_BranchCity;
	CString	m_BranchName;
	CString	m_FindBranch;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CBranchDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CBranchDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnClickList1(NMHDR* pNMHDR, LRESULT* pResult);
	virtual void OnOK();
	afx_msg void OnFindall();
	afx_msg void OnAdd();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_BRANCHDLG_H__77FBC419_4402_4086_89B2_F4BB6468F27C__INCLUDED_)
