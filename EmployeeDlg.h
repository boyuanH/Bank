#if !defined(AFX_EMPLOYEEDLG_H__6CBD65DB_46F7_4745_82AA_AA5455C9C3BE__INCLUDED_)
#define AFX_EMPLOYEEDLG_H__6CBD65DB_46F7_4745_82AA_AA5455C9C3BE__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// EmployeeDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CEmployeeDlg dialog

class CEmployeeDlg : public CDialog
{
// Construction
public:
	CEmployeeDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CEmployeeDlg)
	enum { IDD = IDD_EMPLOYEE_DIALOG };
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CEmployeeDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CEmployeeDlg)
	afx_msg void OnAdduser();
	afx_msg void OnBankinfo();
	afx_msg void OnDeleteuser();
	virtual void OnCancel();
	afx_msg void OnLoan();
	afx_msg void OnAllaccount();
	afx_msg void OnAllloan();
	afx_msg void OnPayment();
	afx_msg void OnPaint();
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_EMPLOYEEDLG_H__6CBD65DB_46F7_4745_82AA_AA5455C9C3BE__INCLUDED_)
