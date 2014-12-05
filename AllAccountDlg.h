#if !defined(AFX_ALLACCOUNTDLG_H__3E545E26_0630_46E3_99F8_F58A1D8E9F8D__INCLUDED_)
#define AFX_ALLACCOUNTDLG_H__3E545E26_0630_46E3_99F8_F58A1D8E9F8D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// AllAccountDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CAllAccountDlg dialog

class CAllAccountDlg : public CDialog
{
// Construction
public:
	void ListAll();
	CAllAccountDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CAllAccountDlg)
	enum { IDD = IDD_ALLACCOUNT };
	CListCtrl	m_ListAccount;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAllAccountDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CAllAccountDlg)
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ALLACCOUNTDLG_H__3E545E26_0630_46E3_99F8_F58A1D8E9F8D__INCLUDED_)
