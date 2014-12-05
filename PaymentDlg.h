#if !defined(AFX_PAYMENTDLG_H__549A8461_94D8_49F0_AEC9_C7053BA8D827__INCLUDED_)
#define AFX_PAYMENTDLG_H__549A8461_94D8_49F0_AEC9_C7053BA8D827__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// PaymentDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CPaymentDlg dialog

class CPaymentDlg : public CDialog
{
// Construction
public:
	int InsertLoan();
	int CheckLoan();
	CPaymentDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CPaymentDlg)
	enum { IDD = IDD_PAYMENTDIALOG };
	CString	m_LoanNumber;
	double	m_Amount;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPaymentDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CPaymentDlg)
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PAYMENTDLG_H__549A8461_94D8_49F0_AEC9_C7053BA8D827__INCLUDED_)
