; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CEmployeeDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "Bank.h"

ClassCount=23
Class1=CBankApp
Class2=CBankDlg

ResourceCount=24
Resource1=IDR_MAINFRAME
Resource2=IDD_REGIST_DIALOG
Class3=CLoginDlg
Resource3=IDD_EMPLOYEE_DIALOG
Class4=CRegisteDlg
Resource4=IDD_MANAGER_DIALOG
Class5=CChangPswd
Resource5=IDD_CHANGEPSWD
Class6=CUserInfoDlg
Resource6=IDD_DETAILDIALOG
Class7=CEmployeeDlg
Resource7=IDD_TRANSFORDIALOG
Class8=CMangerDlg
Resource8=IDD_AMOUNT
Class9=CAmountDlg
Resource9=IDD_LOGIN_DIALOG
Class10=CTakeMoneyDlg
Resource10=IDD_BRANCHDIALOG
Class11=CTransforDlg
Resource11=IDD_DELEMPDIALOG
Class12=CDetailDlg
Resource12=IDD_ALLLOANDIALOG
Class13=CAddUserDlg
Resource13=IDD_ADDUSERDIALOG
Class14=CBranchDlg
Resource14=IDD_BANK_DIALOG
Class15=CDelUserDlg
Resource15=IDD_DELUSERDIALOG
Class16=CAddEmpDlg
Resource16=IDD_MODEMPDLG
Class17=CAllEmpDlg
Resource17=IDD_LOANDIALOG
Class18=CLoanDlg
Resource18=IDD_USERINFO
Class19=CAllAccountDlg
Resource19=IDD_TAKEDIALOG
Class20=CAllLoanDlg
Resource20=IDD_ALLACCOUNT
Class21=CPaymentDlg
Resource21=IDD_PAYMENTDIALOG
Class22=CDelEmpDlg
Resource22=IDD_ALLEMPDIALOG
Class23=CModEmpDlg
Resource23=IDD_ADDEMPDIALOG
Resource24=IDD_DIALOG1

[CLS:CBankApp]
Type=0
HeaderFile=Bank.h
ImplementationFile=Bank.cpp
Filter=N

[CLS:CBankDlg]
Type=0
HeaderFile=BankDlg.h
ImplementationFile=BankDlg.cpp
Filter=D
LastObject=CBankDlg
BaseClass=CDialog
VirtualFilter=dWC



[DLG:IDD_BANK_DIALOG]
Type=1
Class=CBankDlg
ControlCount=8
Control1=IDCANCEL,button,1342242816
Control2=IDC_SAVING,button,1342242816
Control3=IDC_TAKING,button,1342242816
Control4=IDC_ACCOUNT,button,1342242816
Control5=IDC_CHANGEPSWD,button,1342242816
Control6=IDC_TRANSFOR,button,1342242816
Control7=IDC_DETAIL,button,1342242816
Control8=IDC_USERINFO,button,1342242816

[DLG:IDD_LOGIN_DIALOG]
Type=1
Class=CLoginDlg
ControlCount=14
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_STATIC,static,1342308352
Control4=IDC_STATIC,static,1342308352
Control5=IDC_STATIC,static,1342308352
Control6=IDC_USERID,edit,1350631552
Control7=IDC_PASSWORD,edit,1350631584
Control8=IDC_RADIO_CUSTOMER,button,1342308361
Control9=IDC_RADIO_EMPLOYEE,button,1342177289
Control10=IDC_BUTTON_REGIST,button,1342242816
Control11=IDC_RADIO_MANAGER,button,1342177289
Control12=IDC_STATIC,static,1342177283
Control13=IDC_MAINSTATIC,static,1342308352
Control14=IDC_NAME,static,1342308352

[CLS:CLoginDlg]
Type=0
HeaderFile=LoginDlg.h
ImplementationFile=LoginDlg.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=CLoginDlg

[DLG:IDD_REGIST_DIALOG]
Type=1
Class=CRegisteDlg
ControlCount=12
Control1=IDOK,button,1342177281
Control2=IDCANCEL,button,1342242816
Control3=IDC_STATIC,static,1342308352
Control4=IDC_STATIC,static,1342308352
Control5=IDC_STATIC,static,1342308352
Control6=IDC_STATIC,static,1342308352
Control7=IDC_USERID,edit,1350631552
Control8=IDC_USERNAME,edit,1350631552
Control9=IDC_CITY,edit,1350631552
Control10=IDC_STREET,edit,1350631552
Control11=IDC_STATIC,static,1342308352
Control12=IDC_TELEPHONE,edit,1350631552

[CLS:CRegisteDlg]
Type=0
HeaderFile=RegisteDlg.h
ImplementationFile=RegisteDlg.cpp
BaseClass=CDialog
Filter=D
LastObject=IDC_TELEPHONE
VirtualFilter=dWC

[DLG:IDD_CHANGEPSWD]
Type=1
Class=CChangPswd
ControlCount=8
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_NEWPASSWORD,edit,1350631584
Control4=IDC_STATIC,static,1342308352
Control5=IDC_STATIC,static,1342308352
Control6=IDC_STATIC,static,1342308352
Control7=IDC_NEWPASSWORD2,edit,1350631584
Control8=IDC_OLDPASSWORD,edit,1350631584

[CLS:CChangPswd]
Type=0
HeaderFile=ChangPswd.h
ImplementationFile=ChangPswd.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC

[DLG:IDD_USERINFO]
Type=1
Class=CUserInfoDlg
ControlCount=18
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_STATIC,static,1342308352
Control4=IDC_STATIC,static,1342308352
Control5=IDC_STATIC,static,1342308352
Control6=IDC_STATIC,static,1342308352
Control7=IDC_ACCOUNTNUM,edit,1350566016
Control8=IDC_USERNAME,edit,1350566016
Control9=IDC_CITY,edit,1350566016
Control10=IDC_STREET,edit,1350566016
Control11=IDC_BRANCHNAME,edit,1350631552
Control12=IDC_STATIC,static,1342308352
Control13=IDC_STATIC,static,1342308352
Control14=IDC_BRANCHCITY,edit,1350631552
Control15=IDC_STATIC,static,1342308352
Control16=IDC_TELEPHONE,edit,1350566016
Control17=IDC_STATIC,button,1342177287
Control18=IDC_STATIC,button,1342177287

[CLS:CUserInfoDlg]
Type=0
HeaderFile=UserInfoDlg.h
ImplementationFile=UserInfoDlg.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=CUserInfoDlg

[DLG:IDD_EMPLOYEE_DIALOG]
Type=1
Class=CEmployeeDlg
ControlCount=10
Control1=IDCANCEL,button,1342242816
Control2=IDC_ADDUSER,button,1342242816
Control3=IDC_DELETEUSER,button,1342242816
Control4=IDC_BANKINFO,button,1342242816
Control5=IDC_LOAN,button,1342242816
Control6=IDC_PAYMENT,button,1342242816
Control7=IDC_ALLACCOUNT,button,1342242816
Control8=IDC_ALLLOAN,button,1342242816
Control9=IDC_STATIC,static,1342308352
Control10=IDC_EMPLOYEEID,edit,1350631552

[CLS:CEmployeeDlg]
Type=0
HeaderFile=EmployeeDlg.h
ImplementationFile=EmployeeDlg.cpp
BaseClass=CDialog
Filter=D
LastObject=CEmployeeDlg
VirtualFilter=dWC

[DLG:IDD_MANAGER_DIALOG]
Type=1
Class=CMangerDlg
ControlCount=5
Control1=IDCANCEL,button,1342242816
Control2=IDC_ADDEMPLOYEE,button,1342242816
Control3=IDC_DELETEEMPLOYEE,button,1342242816
Control4=IDC_ALLEMPLOYEE,button,1342242816
Control5=IDC_MODIFYEMPLOYEE,button,1342242816

[CLS:CMangerDlg]
Type=0
HeaderFile=MangerDlg.h
ImplementationFile=MangerDlg.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=CMangerDlg

[DLG:IDD_AMOUNT]
Type=1
Class=CAmountDlg
ControlCount=4
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_STATIC,static,1342308352
Control4=IDC_AMOUNT,edit,1350631552

[CLS:CAmountDlg]
Type=0
HeaderFile=AmountDlg.h
ImplementationFile=AmountDlg.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=CAmountDlg

[DLG:IDD_TAKEDIALOG]
Type=1
Class=CTakeMoneyDlg
ControlCount=4
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_STATIC,static,1342308352
Control4=IDC_TAKEMONEY,edit,1350631552

[CLS:CTakeMoneyDlg]
Type=0
HeaderFile=TakeMoneyDlg.h
ImplementationFile=TakeMoneyDlg.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=IDC_TAKEMONEY

[CLS:CTransforDlg]
Type=0
HeaderFile=TransforDlg.h
ImplementationFile=TransforDlg.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=CTransforDlg

[DLG:IDD_TRANSFORDIALOG]
Type=1
Class=CTransforDlg
ControlCount=8
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_STATIC,static,1342308352
Control4=IDC_STATIC,static,1342308352
Control5=IDC_STATIC,static,1342308352
Control6=IDC_DESACCOUNTNUM,edit,1350631552
Control7=IDC_PASSWORD,edit,1350631584
Control8=IDC_DESAMOUNT,edit,1350631552

[DLG:IDD_DETAILDIALOG]
Type=1
Class=CDetailDlg
ControlCount=4
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_STATIC,static,1342308352
Control4=IDC_LIST1,SysListView32,1350631424

[CLS:CDetailDlg]
Type=0
HeaderFile=DetailDlg.h
ImplementationFile=DetailDlg.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=CDetailDlg

[CLS:CAddUserDlg]
Type=0
HeaderFile=AddUserDlg.h
ImplementationFile=AddUserDlg.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=CAddUserDlg

[DLG:IDD_ADDUSERDIALOG]
Type=1
Class=CAddUserDlg
ControlCount=14
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_STATIC,static,1342308352
Control4=IDC_STATIC,static,1342308352
Control5=IDC_STATIC,static,1342308352
Control6=IDC_STATIC,static,1342308352
Control7=IDC_CUSTOMERID,edit,1350631552
Control8=IDC_ACCOUNTNUM,edit,1350631552
Control9=IDC_PASSWORD,edit,1350631584
Control10=IDC_AMOUNT,edit,1350631552
Control11=IDC_STATIC,static,1342308352
Control12=IDC_PASSWORD2,edit,1350631584
Control13=IDC_STATIC,static,1342308352
Control14=IDC_BRANCHNAME,edit,1350631552

[DLG:IDD_BRANCHDIALOG]
Type=1
Class=CBranchDlg
ControlCount=15
Control1=IDCANCEL,button,1342242816
Control2=IDC_STATIC,static,1342308352
Control3=IDC_BRANCHNAME,edit,1350631552
Control4=IDC_STATIC,static,1342308352
Control5=IDC_STATIC,static,1342308352
Control6=IDC_BRANCHCITY,edit,1350631552
Control7=IDC_ASSETS,edit,1350631552
Control8=IDC_LIST1,SysListView32,1350631424
Control9=IDC_ADD,button,1342242816
Control10=IDC_STATIC,button,1342177287
Control11=IDC_STATIC,button,1342177287
Control12=IDC_STATIC,static,1342308352
Control13=IDC_FINDBRANCHNAME,edit,1350631552
Control14=IDOK,button,1342242816
Control15=IDC_FINDALL,button,1342242816

[CLS:CBranchDlg]
Type=0
HeaderFile=BranchDlg.h
ImplementationFile=BranchDlg.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=CBranchDlg

[DLG:IDD_DELUSERDIALOG]
Type=1
Class=CDelUserDlg
ControlCount=4
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_STATIC,static,1342308352
Control4=IDC_ACCOUNTNUM,edit,1350631552

[CLS:CDelUserDlg]
Type=0
HeaderFile=DelUserDlg.h
ImplementationFile=DelUserDlg.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=CDelUserDlg

[DLG:IDD_ADDEMPDIALOG]
Type=1
Class=CAddEmpDlg
ControlCount=14
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_EMPLOYEEID,edit,1350631552
Control4=IDC_EMPPASSWORD,edit,1350631584
Control5=IDC_EMPPASSWORD2,edit,1350631584
Control6=IDC_EMPTELEPHONE,edit,1350631552
Control7=IDC_STARTDATE,edit,1350631552
Control8=IDC_STATIC,static,1342308352
Control9=IDC_STATIC,static,1342308352
Control10=IDC_STATIC,static,1342308352
Control11=IDC_STATIC,static,1342308352
Control12=IDC_STATIC,static,1342308352
Control13=IDC_STATIC,static,1342308352
Control14=IDC_EMPNAME,edit,1350631552

[CLS:CAddEmpDlg]
Type=0
HeaderFile=AddEmpDlg.h
ImplementationFile=AddEmpDlg.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=IDC_EMPPASSWORD

[DLG:IDD_ALLEMPDIALOG]
Type=1
Class=CAllEmpDlg
ControlCount=3
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_LIST1,SysListView32,1350631424

[CLS:CAllEmpDlg]
Type=0
HeaderFile=AllEmpDlg.h
ImplementationFile=AllEmpDlg.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=CAllEmpDlg

[DLG:IDD_LOANDIALOG]
Type=1
Class=CLoanDlg
ControlCount=10
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_STATIC,static,1342308352
Control4=IDC_STATIC,static,1342308352
Control5=IDC_CUSTOMERID,edit,1350631552
Control6=IDC_BRANCHNAME,edit,1350631552
Control7=IDC_STATIC,static,1342308352
Control8=IDC_LOANNUMBER,edit,1350631552
Control9=IDC_STATIC,static,1342308352
Control10=IDC_AMOUNT,edit,1350631552

[CLS:CLoanDlg]
Type=0
HeaderFile=LoanDlg.h
ImplementationFile=LoanDlg.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=CLoanDlg

[DLG:IDD_ALLACCOUNT]
Type=1
Class=CAllAccountDlg
ControlCount=3
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_LIST1,SysListView32,1350631424

[CLS:CAllAccountDlg]
Type=0
HeaderFile=AllAccountDlg.h
ImplementationFile=AllAccountDlg.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=CAllAccountDlg

[DLG:IDD_ALLLOANDIALOG]
Type=1
Class=CAllLoanDlg
ControlCount=3
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_LIST1,SysListView32,1350631424

[CLS:CAllLoanDlg]
Type=0
HeaderFile=AllLoanDlg.h
ImplementationFile=AllLoanDlg.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=CAllLoanDlg

[DLG:IDD_PAYMENTDIALOG]
Type=1
Class=CPaymentDlg
ControlCount=6
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_STATIC,static,1342308352
Control4=IDC_PAYMENTNUMBER,edit,1350631552
Control5=IDC_STATIC,static,1342308352
Control6=IDC_PAYMENTAMOUNT,edit,1350631552

[CLS:CPaymentDlg]
Type=0
HeaderFile=PaymentDlg.h
ImplementationFile=PaymentDlg.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=CPaymentDlg

[DLG:IDD_DELEMPDIALOG]
Type=1
Class=CDelEmpDlg
ControlCount=5
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_STATIC,static,1342308352
Control4=IDC_EMPLOYEEID,edit,1350631552
Control5=IDC_STATIC,button,1342177287

[CLS:CDelEmpDlg]
Type=0
HeaderFile=DelEmpDlg.h
ImplementationFile=DelEmpDlg.cpp
BaseClass=CDialog
Filter=D
LastObject=CDelEmpDlg
VirtualFilter=dWC

[DLG:IDD_MODEMPDLG]
Type=1
Class=CModEmpDlg
ControlCount=12
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_STATIC,static,1342308352
Control4=IDC_STATIC,static,1342308352
Control5=IDC_STATIC,static,1342308352
Control6=IDC_STATIC,static,1342308352
Control7=IDC_EMPLOYEEID,edit,1350631552
Control8=IDC_EMPLOYEENAME,edit,1350631552
Control9=IDC_EMPLOYEETEL,edit,1350631552
Control10=IDC_EMPLOYEEDATE,edit,1350631552
Control11=IDC_STATIC,button,1342177287
Control12=IDC_BUTTONMOD,button,1342242816

[CLS:CModEmpDlg]
Type=0
HeaderFile=ModEmpDlg.h
ImplementationFile=ModEmpDlg.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=CModEmpDlg

[DLG:IDD_DIALOG1]
Type=1
Class=?
ControlCount=2
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816

