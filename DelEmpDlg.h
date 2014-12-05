#if !defined(AFX_DELEMPDLG_H__FCDC9CAB_8066_4A9B_89DC_D6CC9D5BF651__INCLUDED_)
#define AFX_DELEMPDLG_H__FCDC9CAB_8066_4A9B_89DC_D6CC9D5BF651__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DelEmpDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDelEmpDlg dialog

class CDelEmpDlg : public CDialog
{
// Construction
public:
	CDelEmpDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CDelEmpDlg)
	enum { IDD = IDD_DELEMPDIALOG };
	CString	m_EmployeeID;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDelEmpDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDelEmpDlg)
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DELEMPDLG_H__FCDC9CAB_8066_4A9B_89DC_D6CC9D5BF651__INCLUDED_)
