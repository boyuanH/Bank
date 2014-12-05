#if !defined(AFX_MANGERDLG_H__E24D65CF_002C_4778_ADC6_F015C433739F__INCLUDED_)
#define AFX_MANGERDLG_H__E24D65CF_002C_4778_ADC6_F015C433739F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// MangerDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CMangerDlg dialog

class CMangerDlg : public CDialog
{
// Construction
public:
	CMangerDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CMangerDlg)
	enum { IDD = IDD_MANAGER_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMangerDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CMangerDlg)
	afx_msg void OnAddemployee();
	virtual void OnCancel();
	afx_msg void OnAllemployee();
	afx_msg void OnPaint();
	afx_msg void OnDeleteemployee();
	afx_msg void OnModifyemployee();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MANGERDLG_H__E24D65CF_002C_4778_ADC6_F015C433739F__INCLUDED_)
