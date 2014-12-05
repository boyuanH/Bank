#if !defined(AFX_DETAILDLG_H__4C142BB2_69E9_4109_AEFD_AEE66847CC18__INCLUDED_)
#define AFX_DETAILDLG_H__4C142BB2_69E9_4109_AEFD_AEE66847CC18__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DetailDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDetailDlg dialog

class CDetailDlg : public CDialog
{
// Construction
public:
	CDetailDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CDetailDlg)
	enum { IDD = IDD_DETAILDIALOG };
	CListCtrl	m_ListDetail;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDetailDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDetailDlg)
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	void ListAll();
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DETAILDLG_H__4C142BB2_69E9_4109_AEFD_AEE66847CC18__INCLUDED_)
