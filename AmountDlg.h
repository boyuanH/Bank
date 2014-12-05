#if !defined(AFX_AMOUNTDLG_H__B520CE54_561C_4EC5_8A6B_FD832945BE2F__INCLUDED_)
#define AFX_AMOUNTDLG_H__B520CE54_561C_4EC5_8A6B_FD832945BE2F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// AmountDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CAmountDlg dialog

class CAmountDlg : public CDialog
{
// Construction
public:
	CAmountDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CAmountDlg)
	enum { IDD = IDD_AMOUNT };
	double	m_Amount;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAmountDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CAmountDlg)
	virtual BOOL OnInitDialog();
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_AMOUNTDLG_H__B520CE54_561C_4EC5_8A6B_FD832945BE2F__INCLUDED_)
