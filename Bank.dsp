# Microsoft Developer Studio Project File - Name="Bank" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Application" 0x0101

CFG=Bank - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "Bank.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "Bank.mak" CFG="Bank - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "Bank - Win32 Release" (based on "Win32 (x86) Application")
!MESSAGE "Bank - Win32 Debug" (based on "Win32 (x86) Application")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
MTL=midl.exe
RSC=rc.exe

!IF  "$(CFG)" == "Bank - Win32 Release"

# PROP BASE Use_MFC 6
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 6
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Release"
# PROP Intermediate_Dir "Release"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /Yu"stdafx.h" /FD /c
# ADD CPP /nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Yu"stdafx.h" /FD /c
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x804 /d "NDEBUG" /d "_AFXDLL"
# ADD RSC /l 0x804 /d "NDEBUG" /d "_AFXDLL"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /machine:I386
# ADD LINK32 /nologo /subsystem:windows /machine:I386

!ELSEIF  "$(CFG)" == "Bank - Win32 Debug"

# PROP BASE Use_MFC 6
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 6
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "Debug"
# PROP Intermediate_Dir "Debug"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /Yu"stdafx.h" /FD /GZ /c
# ADD CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /FR /Yu"stdafx.h" /FD /GZ /c
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x804 /d "_DEBUG" /d "_AFXDLL"
# ADD RSC /l 0x804 /d "_DEBUG" /d "_AFXDLL"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /debug /machine:I386 /pdbtype:sept
# ADD LINK32 /nologo /subsystem:windows /debug /machine:I386 /pdbtype:sept

!ENDIF 

# Begin Target

# Name "Bank - Win32 Release"
# Name "Bank - Win32 Debug"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Source File

SOURCE=.\AddEmpDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\AddUserDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\ADOConn.cpp
# End Source File
# Begin Source File

SOURCE=.\AllAccountDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\AllEmpDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\AllLoanDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\AmountDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\Bank.cpp
# End Source File
# Begin Source File

SOURCE=.\Bank.rc
# End Source File
# Begin Source File

SOURCE=.\BankDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\BCMenu.cpp
# End Source File
# Begin Source File

SOURCE=.\BranchDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\ButtonST.cpp
# End Source File
# Begin Source File

SOURCE=.\ChangPswd.cpp
# End Source File
# Begin Source File

SOURCE=.\DelEmpDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\DelUserDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\DetailDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\EmployeeDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\LoanDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\LoginDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\MangerDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\ModEmpDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\PaymentDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\RegisteDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\StdAfx.cpp
# ADD CPP /Yc"stdafx.h"
# End Source File
# Begin Source File

SOURCE=.\TakeMoneyDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\TransforDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\UserInfoDlg.cpp
# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# Begin Source File

SOURCE=.\AddEmpDlg.h
# End Source File
# Begin Source File

SOURCE=.\AddUserDlg.h
# End Source File
# Begin Source File

SOURCE=.\ADOConn.h
# End Source File
# Begin Source File

SOURCE=.\AllAccountDlg.h
# End Source File
# Begin Source File

SOURCE=.\AllEmpDlg.h
# End Source File
# Begin Source File

SOURCE=.\AllLoanDlg.h
# End Source File
# Begin Source File

SOURCE=.\AmountDlg.h
# End Source File
# Begin Source File

SOURCE=.\Bank.h
# End Source File
# Begin Source File

SOURCE=.\BankDlg.h
# End Source File
# Begin Source File

SOURCE=.\BCMenu.h
# End Source File
# Begin Source File

SOURCE=.\BranchDlg.h
# End Source File
# Begin Source File

SOURCE=.\ButtonST.h
# End Source File
# Begin Source File

SOURCE=.\ChangPswd.h
# End Source File
# Begin Source File

SOURCE=.\DelEmpDlg.h
# End Source File
# Begin Source File

SOURCE=.\DelUserDlg.h
# End Source File
# Begin Source File

SOURCE=.\DetailDlg.h
# End Source File
# Begin Source File

SOURCE=.\EmployeeDlg.h
# End Source File
# Begin Source File

SOURCE=.\LoanDlg.h
# End Source File
# Begin Source File

SOURCE=.\LoginDlg.h
# End Source File
# Begin Source File

SOURCE=.\MangerDlg.h
# End Source File
# Begin Source File

SOURCE=.\ModEmpDlg.h
# End Source File
# Begin Source File

SOURCE=.\PaymentDlg.h
# End Source File
# Begin Source File

SOURCE=.\RegisteDlg.h
# End Source File
# Begin Source File

SOURCE=.\Resource.h
# End Source File
# Begin Source File

SOURCE=.\StdAfx.h
# End Source File
# Begin Source File

SOURCE=.\TakeMoneyDlg.h
# End Source File
# Begin Source File

SOURCE=.\TransforDlg.h
# End Source File
# Begin Source File

SOURCE=.\UserInfoDlg.h
# End Source File
# End Group
# Begin Group "Resource Files"

# PROP Default_Filter "ico;cur;bmp;dlg;rc2;rct;bin;rgs;gif;jpg;jpeg;jpe"
# Begin Source File

SOURCE=.\res\005.bmp
# End Source File
# Begin Source File

SOURCE=.\res\08b1OOOPIC97.jpg
# End Source File
# Begin Source File

SOURCE=.\res\Bank.ico
# End Source File
# Begin Source File

SOURCE=.\res\Bank.rc2
# End Source File
# Begin Source File

SOURCE=.\res\bitmap1.bmp
# End Source File
# Begin Source File

SOURCE=.\res\harry.bmp
# End Source File
# Begin Source File

SOURCE=.\res\idr_mian.bin
# End Source File
# Begin Source File

SOURCE=.\res\source3.bmp
# End Source File
# Begin Source File

SOURCE=".\res\管理员.ico"
# End Source File
# Begin Source File

SOURCE=".\res\可爱.ico"
# End Source File
# Begin Source File

SOURCE=".\res\绿色水珠.bmp"
# End Source File
# Begin Source File

SOURCE=".\res\用户.ico"
# End Source File
# Begin Source File

SOURCE=".\res\员工.ico"
# End Source File
# End Group
# Begin Source File

SOURCE=.\ReadMe.txt
# End Source File
# End Target
# End Project
