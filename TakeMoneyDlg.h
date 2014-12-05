#if !defined(AFX_TAKEMONEYDLG_H__B6DB0781_D0F1_4908_B268_EECE8CD0E474__INCLUDED_)
#define AFX_TAKEMONEYDLG_H__B6DB0781_D0F1_4908_B268_EECE8CD0E474__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// TakeMoneyDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CTakeMoneyDlg dialog

class CTakeMoneyDlg : public CDialog
{
// Construction
public:
	CTakeMoneyDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CTakeMoneyDlg)
	enum { IDD = IDD_TAKEDIALOG };
	double	m_Amount;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTakeMoneyDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CTakeMoneyDlg)
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TAKEMONEYDLG_H__B6DB0781_D0F1_4908_B268_EECE8CD0E474__INCLUDED_)
