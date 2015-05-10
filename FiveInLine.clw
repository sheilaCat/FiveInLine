; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CMainGameDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "FiveInLine.h"

ClassCount=12
Class1=CFiveInLineApp
Class2=CFiveInLineDlg
Class3=CAboutDlg

ResourceCount=8
Resource1=IDD_LOGIN_DIALOG
Resource2=IDR_MAINFRAME
Resource3=IDD_ABOUTBOX
Class4=CMainGameDlg
Class5=CChatSocket
Class6=CClientSocket
Class7=CSrvSocket
Resource4=IDD_END_DIALOG
Class8=CEndDlg
Resource5=IDD_FIVEINLINE_DIALOG
Class9=CPromptDlg
Resource6=IDD_MAINGAME_DIALOG
Class10=CLoginDlg
Class11=CGameModelDlg
Resource7=IDD_PROMPT_DIALOG
Class12=CGameChooseDlg
Resource8=IDD_GAMECHOOSE_DIALOG

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
ControlCount=2
Control1=IDC_CLOSEBTN,button,1342242955
Control2=IDC_STARTGAME,button,1342242955

[DLG:IDD_MAINGAME_DIALOG]
Type=1
Class=CMainGameDlg
ControlCount=8
Control1=IDC_BUTMUSIC,button,1342242955
Control2=IDC_BUTAGAIN,button,1342242955
Control3=IDC_BUTREGRET,button,1342242955
Control4=IDC_BUTEXIT,button,1342242955
Control5=IDC_EDIT_MSG,edit,1342242944
Control6=IDC_BUTTON_SEND,button,1342242955
Control7=IDC_RICHEDIT,RICHEDIT,1342244932
Control8=IDC_CANCEL,button,1342242955

[CLS:CMainGameDlg]
Type=0
HeaderFile=ui\maingamedlg.h
ImplementationFile=ui\maingamedlg.cpp
BaseClass=CDialog
LastObject=IDC_BUTMUSIC
Filter=D
VirtualFilter=dWC

[CLS:CChatSocket]
Type=0
HeaderFile=ChatSocket.h
ImplementationFile=ChatSocket.cpp
BaseClass=CSocket
Filter=N
VirtualFilter=uq
LastObject=CChatSocket

[CLS:CClientSocket]
Type=0
HeaderFile=ClientSocket.h
ImplementationFile=ClientSocket.cpp
BaseClass=CSocket
Filter=N
VirtualFilter=uq
LastObject=CClientSocket

[CLS:CSrvSocket]
Type=0
HeaderFile=data\srvsocket.h
ImplementationFile=data\srvsocket.cpp
BaseClass=CSocket
LastObject=CSrvSocket

[DLG:IDD_END_DIALOG]
Type=1
Class=CEndDlg
ControlCount=1
Control1=IDOK,button,1342242955

[CLS:CEndDlg]
Type=0
HeaderFile=ui\enddlg.h
ImplementationFile=ui\enddlg.cpp
BaseClass=CDialog
LastObject=CEndDlg
Filter=D
VirtualFilter=dWC

[DLG:IDD_PROMPT_DIALOG]
Type=1
Class=CPromptDlg
ControlCount=2
Control1=IDOK,button,1342242955
Control2=IDCANCEL,button,1342242955

[CLS:CPromptDlg]
Type=0
HeaderFile=ui\promptdlg.h
ImplementationFile=ui\promptdlg.cpp
BaseClass=CDialog
LastObject=CPromptDlg
Filter=D
VirtualFilter=dWC

[DLG:IDD_LOGIN_DIALOG]
Type=1
Class=CLoginDlg
ControlCount=4
Control1=IDOK,button,1342242955
Control2=IDC_NAME,edit,1350631552
Control3=IDC_IPADDRESS,SysIPAddress32,1342242816
Control4=IDC_BUTEXIT,button,1342242955

[CLS:CLoginDlg]
Type=0
HeaderFile=ui\logindlg.h
ImplementationFile=ui\logindlg.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=CLoginDlg

[CLS:CGameModelDlg]
Type=0
HeaderFile=ui\gamemodeldlg.h
ImplementationFile=ui\gamemodeldlg.cpp
BaseClass=CDialog
LastObject=CGameModelDlg

[DLG:IDD_GAMECHOOSE_DIALOG]
Type=1
Class=CGameChooseDlg
ControlCount=5
Control1=IDC_CLOSEBTN,button,1342242955
Control2=IDC_SINGLEGAME,button,1342242955
Control3=IDC_DOUBLEGAME,button,1342242955
Control4=IDC_CREATE,button,1342242955
Control5=IDC_CONNECT,button,1342242955

[CLS:CGameChooseDlg]
Type=0
HeaderFile=GameChooseDlg.h
ImplementationFile=GameChooseDlg.cpp
BaseClass=CDialog
Filter=D
LastObject=CGameChooseDlg
VirtualFilter=dWC

