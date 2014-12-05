#if !defined(AFX_MODEMPDLG_H__EADDBAB8_E35B_4D39_9425_23DD8FCAB671__INCLUDED_)
#define AFX_MODEMPDLG_H__EADDBAB8_E35B_4D39_9425_23DD8FCAB671__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ModEmpDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CModEmpDlg dialog

class CModEmpDlg : public CDialog
{
// Construction
public:
	CModEmpDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CModEmpDlg)
	enum { IDD = IDD_MODEMPDLG };
	CString	m_EmployeeDate;
	CString	m_EmployeeID;
	CString	m_EmployeeName;
	CString	m_EmployeeTel;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CModEmpDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CModEmpDlg)
	virtual void OnOK();
	virtual BOOL OnInitDialog();
	afx_msg void OnButtonmod();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MODEMPDLG_H__EADDBAB8_E35B_4D39_9425_23DD8FCAB671__INCLUDED_)
