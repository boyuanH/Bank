#if !defined(AFX_TRANSFORDLG_H__81834E2B_5E6E_4101_B420_573A67BCD771__INCLUDED_)
#define AFX_TRANSFORDLG_H__81834E2B_5E6E_4101_B420_573A67BCD771__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// TransforDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CTransforDlg dialog

class CTransforDlg : public CDialog
{
// Construction
public:
	CTransforDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CTransforDlg)
	enum { IDD = IDD_TRANSFORDIALOG };
	CString	m_DesAccountNum;
	double	m_DesAmount;
	CString	m_Password;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTransforDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CTransforDlg)
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TRANSFORDLG_H__81834E2B_5E6E_4101_B420_573A67BCD771__INCLUDED_)
