// BankDlg.h : header file
//

#if !defined(AFX_BANKDLG_H__59A57CDB_3B19_46D4_9DA7_956FF9C81010__INCLUDED_)
#define AFX_BANKDLG_H__59A57CDB_3B19_46D4_9DA7_956FF9C81010__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CBankDlg dialog

class CBankDlg : public CDialog
{
// Construction
public:
	CBankDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CBankDlg)
	enum { IDD = IDD_BANK_DIALOG };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CBankDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CBankDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnChangepswd();
	afx_msg void OnUserinfo();
	virtual void OnCancel();
	afx_msg void OnSaving();
	afx_msg void OnAccount();
	afx_msg void OnTaking();
	afx_msg void OnTransfor();
	afx_msg void OnDetail();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_BANKDLG_H__59A57CDB_3B19_46D4_9DA7_956FF9C81010__INCLUDED_)
