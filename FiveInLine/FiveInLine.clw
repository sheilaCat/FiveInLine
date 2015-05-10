; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CMainGameDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "FiveInLine.h"

ClassCount=4
Class1=CFiveInLineApp
Class2=CFiveInLineDlg
Class3=CAboutDlg

ResourceCount=4
Resource1=IDD_FIVEINLINE_DIALOG
Resource2=IDR_MAINFRAME
Resource3=IDD_ABOUTBOX
Class4=CMainGameDlg
Resource4=IDD_MAINGAME_DIALOG

[CLS:CFiveInLineApp]
Type=0
HeaderFile=FiveInLine.h
ImplementationFile=FiveInLine.cpp
Filter=N

[CLS:CFiveInLineDlg]
Type=0
HeaderFile=FiveInLineDlg.h
ImplementationFile=FiveInLineDlg.cpp
Filter=D
LastObject=CFiveInLineDlg
BaseClass=CDialog
VirtualFilter=dWC

[CLS:CAboutDlg]
Type=0
HeaderFile=FiveInLineDlg.h
ImplementationFile=FiveInLineDlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_FIVEINLINE_DIALOG]
Type=1
Class=CFiveInLineDlg
ControlCount=3
Control1=IDC_TWOSTATE,button,1342242955
Control2=IDC_CLOSEBTN,button,1342242955
Control3=IDC_STARTGAME,button,1342242955

[DLG:IDD_MAINGAME_DIALOG]
Type=1
Class=CMainGameDlg
ControlCount=4
Control1=IDC_BUTMUSIC,button,1342242955
Control2=IDC_BUTAGAIN,button,1342242955
Control3=IDC_BUTREGRET,button,1342242955
Control4=IDC_BUTEXIT,button,1342242955

[CLS:CMainGameDlg]
Type=0
HeaderFile=MainGameDlg.h
ImplementationFile=MainGameDlg.cpp
BaseClass=CDialog
Filter=D
LastObject=CMainGameDlg
VirtualFilter=dWC

