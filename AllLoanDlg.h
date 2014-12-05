#if !defined(AFX_ALLLOANDLG_H__3CD96C96_5C6C_4CEE_9905_DF9700B3D486__INCLUDED_)
#define AFX_ALLLOANDLG_H__3CD96C96_5C6C_4CEE_9905_DF9700B3D486__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// AllLoanDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CAllLoanDlg dialog

class CAllLoanDlg : public CDialog
{
// Construction
public:
	void ListAll();
	CAllLoanDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CAllLoanDlg)
	enum { IDD = IDD_ALLLOANDIALOG };
	CListCtrl	m_ListLoan;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAllLoanDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CAllLoanDlg)
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ALLLOANDLG_H__3CD96C96_5C6C_4CEE_9905_DF9700B3D486__INCLUDED_)
