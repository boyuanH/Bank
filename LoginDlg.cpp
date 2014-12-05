// LoginDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Bank.h"
#include "LoginDlg.h"
#include "ADOConn.h"
#include "BankDlg.h"
#include "LoginDlg.h"
#include "RegisteDlg.h"
#include "EmployeeDlg.h"
#include "MangerDlg.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CLoginDlg dialog

extern CString g_CustomerID;
extern int g_UserType;

CLoginDlg::CLoginDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CLoginDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CLoginDlg)
	m_Password = _T("");
	m_UserType = -1;
	m_UserID = _T("");
	//}}AFX_DATA_INIT
	m_iLoginCount=0;
}


void CLoginDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CLoginDlg)
	DDX_Text(pDX, IDC_PASSWORD, m_Password);
	DDX_Radio(pDX, IDC_RADIO_CUSTOMER, m_UserType);
	DDX_Text(pDX, IDC_USERID, m_UserID);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CLoginDlg, CDialog)
	//{{AFX_MSG_MAP(CLoginDlg)
	ON_BN_CLICKED(IDC_RADIO_CUSTOMER, OnRadioCustomer)
	ON_BN_CLICKED(IDC_RADIO_EMPLOYEE, OnRadioEmployee)
	ON_BN_CLICKED(IDC_BUTTON_REGIST, OnButtonRegist)
	ON_BN_CLICKED(IDC_RADIO1, OnRadio1)
	ON_WM_PAINT()
	ON_WM_CTLCOLOR()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CLoginDlg message handlers

void  CLoginDlg::OnOK() 
{
	// TODO: Add extra validation here
	BOOL bLogOn=FALSE;
	UpdateData(true);
	if(m_UserID=="")
	{
		MessageBox("请输入账号！");
		return;
	}
	if(m_Password=="")
	{
		MessageBox("请输入密码！");
		return;
	}
	CADOConn m_ADOConn;
	m_ADOConn.OnInitADOConn(); //打开数据库连接
	_RecordsetPtr m_pRecordset;//定义记录集指针
	CString strPswd;
	_variant_t theValue;  //取得相关属性值
	if(m_UserType==1)//银行雇员登录
	{
		_bstr_t empSQL="Select * from employee where employee_id='"+m_UserID+"'";
		m_pRecordset=m_ADOConn.GetRecordset(empSQL);
		if(m_pRecordset->adoEOF) //入股记录集是空的
		{
			MessageBox("账号不存在");
			return;
		}
	
		theValue=m_pRecordset->GetCollect("employee_pswd");
		if(theValue.vt!=VT_NULL)
			strPswd=(char *)_bstr_t(theValue);
		if(strPswd==m_Password)
		{
			bLogOn=TRUE;
			CBankApp* App=(CBankApp*)AfxGetApp();
		}
		if(bLogOn)
		{
			g_CustomerID=m_UserID;
			g_UserType=m_UserType; //用户类型
			EndDialog(IDOK);//登录成功，关闭对话框
			CEmployeeDlg dlg;
			dlg.DoModal();
		}
		else
		{
			m_iLoginCount++;
			if(m_iLoginCount>=3)
			{
				MessageBox("用户信息不正确，输入错误密码超过三次，无法登录！");
				this->EndDialog(0);
			}
			else
			{
				MessageBox("密码不正确，请重新输入！");
				GetDlgItem(IDC_PASSWORD)->SetWindowText("");
				return;
			}
		}
	}
	else if(m_UserType==0)  //普通用户登录
	{
		_bstr_t custSQL="Select * from account where account_number='"+m_UserID+"'";
		m_pRecordset=m_ADOConn.GetRecordset(custSQL);
		if(m_pRecordset->adoEOF) //入股记录集是空的
		{
			MessageBox("该客户账号不存在");
			return;
		}
		theValue=m_pRecordset->GetCollect("account_pswd");
		if(theValue.vt!=VT_NULL)
			strPswd=(char *)_bstr_t(theValue);
		if(strPswd==m_Password)
		{
			bLogOn=TRUE;
			CBankApp* App=(CBankApp*)AfxGetApp();
		}
		if(bLogOn)
		{
			g_CustomerID=m_UserID;
			g_UserType=m_UserType;//用户类型
			EndDialog(IDOK);//登录成功，关闭对话框
			CBankDlg dlg;
			dlg.DoModal();
		}
		else
		{
			m_iLoginCount++;
			if(m_iLoginCount>=3)
			{
				MessageBox("用户信息不正确，输入错误密码超过三次，无法登录！");
				this->EndDialog(0);
			}
			else
			{
				MessageBox("密码不正确，请重新输入！");
				GetDlgItem(IDC_PASSWORD)->SetWindowText("");
				return;
			}
		}
	}
	else   //经理登录
	{
		_bstr_t manaSQL="Select * from manager where manager_id='"+m_UserID+"'";
		m_pRecordset=m_ADOConn.GetRecordset(manaSQL);
		if(m_pRecordset->adoEOF) //入股记录集是空的
		{
			MessageBox("账号不存在");
			return;
		}
		theValue=m_pRecordset->GetCollect("manager_pswd");
		if(theValue.vt!=VT_NULL)
			strPswd=(char *)_bstr_t(theValue);
		if(strPswd==m_Password)
		{
			bLogOn=TRUE;
			CBankApp* App=(CBankApp*)AfxGetApp();
		}
		if(bLogOn)
		{
			g_CustomerID=m_UserID;
			g_UserType=m_UserType;//用户类型
			EndDialog(IDOK);//登录成功，关闭对话框
			CMangerDlg dlg;
			dlg.DoModal();
		}
		else
		{
			m_iLoginCount++;
			if(m_iLoginCount>=3)
			{
				MessageBox("用户信息不正确，输入错误密码超过三次，无法登录！");
				this->EndDialog(0);
			}
			else
			{
				MessageBox("密码不正确，请重新输入！");
				GetDlgItem(IDC_PASSWORD)->SetWindowText("");
				return;
			}
		}
	}
	m_ADOConn.ExitConnect();//断开数据源连接
	CDialog::OnOK();
}

void CLoginDlg::OnRadioCustomer() 
{
	// TODO: Add your control notification handler code here
	m_UserType=0;
}

void CLoginDlg::OnRadioEmployee() 
{
	// TODO: Add your control notification handler code here
	m_UserType=1;
}

BOOL CLoginDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	// TODO: Add extra initialization here
	m_btn.SubclassDlgItem(IDC_BUTTON_REGIST,this);
	m_btn.SetIcon(IDI_ICON1);
	m_btn.SetFlat(FALSE);
	m_btn.SetAlign(CButtonST::ST_ALIGN_VERT);
	m_btn.SetTooltipText(_T("This is a tooltip.\r\nMultiline!"));
	CheckDlgButton(IDC_RADIO_CUSTOMER,BST_CHECKED);
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CLoginDlg::OnButtonRegist() 
{
	// TODO: Add your control notification handler code here
	CRegisteDlg rdlg;
	rdlg.DoModal();

}

void CLoginDlg::OnCancel() 
{
	// TODO: Add extra cleanup here
	if(MessageBox("确实要退出系统吗？","退出提示",MB_YESNO|MB_ICONQUESTION)==IDYES)
		CDialog::OnCancel();
}

void CLoginDlg::OnRadio1() 
{
	// TODO: Add your control notification handler code here
	m_UserType=2;
}

void CLoginDlg::OnPaint() 
{
	CPaintDC dc(this); // device context for painting
	
	// TODO: Add your message handler code here 
	CRect   rect; 
	GetClientRect(&rect); 
	CDC   dcMem; 
	dcMem.CreateCompatibleDC(&dc); 
	CBitmap   bmpBackground; 
	bmpBackground.LoadBitmap(IDB_BITMAP1); 
	//IDB_BITMAP是你自己的图对应的ID 
	BITMAP   bitmap; 
	bmpBackground.GetBitmap(&bitmap); 
	CBitmap   *pbmpOld=dcMem.SelectObject(&bmpBackground); 
	dc.StretchBlt(0,0,rect.Width(),rect.Height(),&dcMem,0,0,\
		bitmap.bmWidth,bitmap.bmHeight,SRCCOPY); 
	// Do not call CDialog::OnPaint() for painting messages
}

HBRUSH CLoginDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor) 
{
	HBRUSH hbr = CDialog::OnCtlColor(pDC, pWnd, nCtlColor);
	// TODO: Change any attributes of the DC here
	
	if(pWnd->GetDlgCtrlID()==IDC_MAINSTATIC)
	{
		CFont font;
		font.CreatePointFont(300,"宋体");
		pDC->SelectObject(&font);
		pDC->SetTextColor(RGB(255,255,0));
		pDC->SetBkMode(TRANSPARENT);
		return (HBRUSH)GetStockObject(HOLLOW_BRUSH);
	}
 	if(pWnd->GetDlgCtrlID()==IDC_NAME)
	{
		CFont font;
		font.CreatePointFont(100,"仿宋");
		pDC->SelectObject(&font);
		pDC->SetBkMode(TRANSPARENT);
		pDC->SetTextColor(RGB(255,25,25));
		pDC->SetBkColor(RGB(155,155,155));
		return   (HBRUSH)::GetStockObject(NULL_BRUSH);   
	}
	if(nCtlColor == CTLCOLOR_STATIC)
    {
		pDC->SetTextColor(RGB(255,255,0));
        pDC->SetBkMode(TRANSPARENT);   
        return   (HBRUSH)::GetStockObject(NULL_BRUSH);   
    }
	return hbr;
}
