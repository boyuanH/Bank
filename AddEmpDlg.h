#if !defined(AFX_ADDEMPDLG_H__21EFF885_3901_4AE3_AE84_FD1E382AF0DF__INCLUDED_)
#define AFX_ADDEMPDLG_H__21EFF885_3901_4AE3_AE84_FD1E382AF0DF__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// AddEmpDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CAddEmpDlg dialog

class CAddEmpDlg : public CDialog
{
// Construction
public:
	void InsertEmployee();
	int CheckEmployee();
	CAddEmpDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CAddEmpDlg)
	enum { IDD = IDD_ADDEMPDIALOG };
	CString	m_EmployeeID;
	CString	m_EmpPassword;
	CString	m_EmpPassword2;
	CString	m_EmpTelephone;
	CString	m_StartDate;
	CString	m_EmpName;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAddEmpDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CAddEmpDlg)
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ADDEMPDLG_H__21EFF885_3901_4AE3_AE84_FD1E382AF0DF__INCLUDED_)
