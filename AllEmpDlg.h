#if !defined(AFX_ALLEMPDLG_H__D0AF80EA_ED40_42BD_BEC0_5FD9DF83D27F__INCLUDED_)
#define AFX_ALLEMPDLG_H__D0AF80EA_ED40_42BD_BEC0_5FD9DF83D27F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// AllEmpDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CAllEmpDlg dialog

class CAllEmpDlg : public CDialog
{
// Construction
public:
	void ListAll();
	CAllEmpDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CAllEmpDlg)
	enum { IDD = IDD_ALLEMPDIALOG };
	CListCtrl	m_ListAllEmp;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAllEmpDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CAllEmpDlg)
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ALLEMPDLG_H__D0AF80EA_ED40_42BD_BEC0_5FD9DF83D27F__INCLUDED_)
