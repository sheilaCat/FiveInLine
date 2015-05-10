# Microsoft Developer Studio Project File - Name="FiveInLine" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Application" 0x0101

CFG=FiveInLine - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "FiveInLine.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "FiveInLine.mak" CFG="FiveInLine - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "FiveInLine - Win32 Release" (based on "Win32 (x86) Application")
!MESSAGE "FiveInLine - Win32 Debug" (based on "Win32 (x86) Application")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
MTL=midl.exe
RSC=rc.exe

!IF  "$(CFG)" == "FiveInLine - Win32 Release"

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

!ELSEIF  "$(CFG)" == "FiveInLine - Win32 Debug"

# PROP BASE Use_MFC 6
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 6
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "Debug"
# PROP Intermediate_Dir "Debug"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /Yu"stdafx.h" /FD /GZ /c
# ADD CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Yu"stdafx.h" /FD /GZ /c
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

# Name "FiveInLine - Win32 Release"
# Name "FiveInLine - Win32 Debug"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Source File

SOURCE=.\Data\ChatSocket.cpp
# End Source File
# Begin Source File

SOURCE=.\Data\ClientSocket.cpp
# End Source File
# Begin Source File

SOURCE=.\UI\ColorBtn.cpp
# End Source File
# Begin Source File

SOURCE=.\UI\ColorStatic.cpp
# End Source File
# Begin Source File

SOURCE=.\UI\EndDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\FiveInLine.cpp
# End Source File
# Begin Source File

SOURCE=.\FiveInLine.rc
# End Source File
# Begin Source File

SOURCE=.\UI\FiveInLineDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\GameChooseDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\UI\LoginDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\UI\MainGameDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\UI\PromptDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\Data\SrvSocket.cpp
# End Source File
# Begin Source File

SOURCE=.\Data\Stack.cpp
# End Source File
# Begin Source File

SOURCE=.\Logic\Statistics.cpp
# End Source File
# Begin Source File

SOURCE=.\StdAfx.cpp
# ADD CPP /Yc"stdafx.h"
# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# Begin Source File

SOURCE=.\Data\ChatSocket.h
# End Source File
# Begin Source File

SOURCE=.\Data\ClientSocket.h
# End Source File
# Begin Source File

SOURCE=.\UI\ColorBtn.h
# End Source File
# Begin Source File

SOURCE=.\UI\ColorStatic.h
# End Source File
# Begin Source File

SOURCE=.\UI\EndDlg.h
# End Source File
# Begin Source File

SOURCE=.\FiveInLine.h
# End Source File
# Begin Source File

SOURCE=.\UI\FiveInLineDlg.h
# End Source File
# Begin Source File

SOURCE=.\GameChooseDlg.h
# End Source File
# Begin Source File

SOURCE=.\UI\LoginDlg.h
# End Source File
# Begin Source File

SOURCE=.\UI\MainGameDlg.h
# End Source File
# Begin Source File

SOURCE=.\UI\PromptDlg.h
# End Source File
# Begin Source File

SOURCE=.\Resource.h
# End Source File
# Begin Source File

SOURCE=.\Data\SrvSocket.h
# End Source File
# Begin Source File

SOURCE=.\Data\Stack.h
# End Source File
# Begin Source File

SOURCE=.\Logic\Statistics.h
# End Source File
# Begin Source File

SOURCE=.\StdAfx.h
# End Source File
# End Group
# Begin Group "Resource Files"

# PROP Default_Filter "ico;cur;bmp;dlg;rc2;rct;bin;rgs;gif;jpg;jpeg;jpe"
# Begin Source File

SOURCE=.\res\114.bmp
# End Source File
# Begin Source File

SOURCE=.\res\115.bmp
# End Source File
# Begin Source File

SOURCE=.\res\116.bmp
# End Source File
# Begin Source File

SOURCE=.\res\117.bmp
# End Source File
# Begin Source File

SOURCE=.\res\119.bmp
# End Source File
# Begin Source File

SOURCE=.\res\123.bmp
# End Source File
# Begin Source File

SOURCE=.\res\124.BMP
# End Source File
# Begin Source File

SOURCE=.\res\125.bmp
# End Source File
# Begin Source File

SOURCE=.\res\126.BMP
# End Source File
# Begin Source File

SOURCE=.\res\128.bmp
# End Source File
# Begin Source File

SOURCE=.\res\129.bmp
# End Source File
# Begin Source File

SOURCE=.\res\131.bmp
# End Source File
# Begin Source File

SOURCE=.\res\132.bmp
# End Source File
# Begin Source File

SOURCE=.\res\background.bmp
# End Source File
# Begin Source File

SOURCE=.\res\bitmap1.bmp
# End Source File
# Begin Source File

SOURCE=.\res\Black.bmp
# End Source File
# Begin Source File

SOURCE=.\res\Board.bmp
# End Source File
# Begin Source File

SOURCE=.\res\btn1.bmp
# End Source File
# Begin Source File

SOURCE=.\res\btn2.bmp
# End Source File
# Begin Source File

SOURCE=.\res\BTNWINLOSE.bmp
# End Source File
# Begin Source File

SOURCE=.\res\Document0000.cur
# End Source File
# Begin Source File

SOURCE=.\res\Document0005.cur
# End Source File
# Begin Source File

SOURCE=.\res\EXITGAME.bmp
# End Source File
# Begin Source File

SOURCE=.\res\FiveInLine.ico
# End Source File
# Begin Source File

SOURCE=.\res\FiveInLine.rc2
# End Source File
# Begin Source File

SOURCE=".\res\flat-02.bmp"
# End Source File
# Begin Source File

SOURCE=.\res\gamechoosebg.bmp
# End Source File
# Begin Source File

SOURCE=.\res\go1.bmp
# End Source File
# Begin Source File

SOURCE=.\res\go2.bmp
# End Source File
# Begin Source File

SOURCE=.\res\HAND.CUR
# End Source File
# Begin Source File

SOURCE=.\res\hand_v.cur
# End Source File
# Begin Source File

SOURCE=.\res\icon1.ico
# End Source File
# Begin Source File

SOURCE=.\res\Lose.bmp
# End Source File
# Begin Source File

SOURCE=".\res\reg (2).bmp"
# End Source File
# Begin Source File

SOURCE=.\res\reg.bmp
# End Source File
# Begin Source File

SOURCE=.\res\tipbtn1.bmp
# End Source File
# Begin Source File

SOURCE=.\res\tipbtn2.bmp
# End Source File
# Begin Source File

SOURCE=.\res\tipbtn3.bmp
# End Source File
# Begin Source File

SOURCE=.\res\tipbtn4.bmp
# End Source File
# Begin Source File

SOURCE=.\res\White.bmp
# End Source File
# Begin Source File

SOURCE=.\res\Win.bmp
# End Source File
# Begin Source File

SOURCE=".\res\创建服务器1.bmp"
# End Source File
# Begin Source File

SOURCE=".\res\创建服务器2.bmp"
# End Source File
# Begin Source File

SOURCE=".\res\单人模式1.bmp"
# End Source File
# Begin Source File

SOURCE=".\res\单人模式2.bmp"
# End Source File
# Begin Source File

SOURCE=".\res\发送1.bmp"
# End Source File
# Begin Source File

SOURCE=".\res\发送2.bmp"
# End Source File
# Begin Source File

SOURCE=".\res\悔棋1.bmp"
# End Source File
# Begin Source File

SOURCE=".\res\悔棋2.bmp"
# End Source File
# Begin Source File

SOURCE=".\res\截图00.bmp"
# End Source File
# Begin Source File

SOURCE=".\res\截图01.bmp"
# End Source File
# Begin Source File

SOURCE=".\res\连接服务器.bmp"
# End Source File
# Begin Source File

SOURCE=".\res\连接服务器2.bmp"
# End Source File
# Begin Source File

SOURCE=".\res\双人模式1.bmp"
# End Source File
# Begin Source File

SOURCE=".\res\双人模式2.bmp"
# End Source File
# Begin Source File

SOURCE=".\res\退出游戏1.bmp"
# End Source File
# Begin Source File

SOURCE=".\res\退出游戏2.bmp"
# End Source File
# Begin Source File

SOURCE=".\res\音乐关.bmp"
# End Source File
# Begin Source File

SOURCE=".\res\音乐开.bmp"
# End Source File
# Begin Source File

SOURCE=".\res\重新开始1.bmp"
# End Source File
# Begin Source File

SOURCE=".\res\重新开始2.bmp"
# End Source File
# End Group
# Begin Source File

SOURCE=.\ReadMe.txt
# End Source File
# End Target
# End Project
