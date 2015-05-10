// FiveInLineDlg.cpp : implementation file
//

#include "stdafx.h"
#include "..\FiveInLine.h"
#include "FiveInLineDlg.h"
#include "MainGameDlg.h"
#include "..\GameChooseDlg.h"
#include <mmsystem.h>               //音乐
#pragma comment(lib, "winmm.lib")   //音乐

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CFiveInLineDlg dialog

CFiveInLineDlg::CFiveInLineDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CFiveInLineDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CFiveInLineDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CFiveInLineDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CFiveInLineDlg)
	DDX_Control(pDX, IDC_CLOSEBTN, m_bmpbtnClose);
//	DDX_Control(pDX, IDC_TWOSTATE, m_bmpbtnTwoState);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CFiveInLineDlg, CDialog)
	//{{AFX_MSG_MAP(CFiveInLineDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_CLOSEBTN, OnClose)
	ON_BN_CLICKED(IDC_STARTGAME, OnStartgame)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CFiveInLineDlg message handlers

/////////引入对话框打开与关闭效果/////////////////
#define AW_CENTER                   0x00000010		//动画
#define AW_HIDE                     0x00010000		//隐藏
/////////////////////////////////////////////////

/*****************************
*Create date : 2013/7/10
*Use for : 在打开窗口前初始化窗口
*Function Name : OnInitDialog
*****************************/

BOOL CFiveInLineDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	//设置窗口阴影
	SetClassLong(this->m_hWnd, GCL_STYLE, GetClassLong(this->m_hWnd, GCL_STYLE) | 0x00020000);

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	//修改窗口样式（去掉边框）
	ModifyStyle (WS_CAPTION, WS_MINIMIZEBOX, SWP_DRAWFRAME);
	SetWindowText (_T ("asdf"));
	
	SetIcon (m_hIcon, TRUE);
	SetIcon (m_hIcon, FALSE);

	//载入背景图片
	m_bmpBackGround.LoadBitmap (IDB_BITMAPBACKGROUND);

	//关联按钮和与之对应的成员变量，加载按钮图片
	m_bmpbtnClose.LoadBitmaps (IDB_BITMAPCLOSENORMAL,IDB_BITMAPDOWN);
	m_bmpbtnStart.LoadBitmaps(IDB_BITMAPSTARTUP,IDB_BITMAPSTARTDOWN);
	m_bmpbtnStart.SubclassDlgItem(IDC_STARTGAME,this);					//子类化该按钮控件
	m_bmpbtnStart.SizeToContent();										//把按钮大小设置为位图大小

	
	//////////////////////打开与关闭窗口特效////////////

	CenterWindow ();	
	DWORD dwStyle = AW_CENTER;
	HINSTANCE hInst = LoadLibrary("User32.DLL"); 
	
	typedef BOOL (WINAPI MYFUNC (HWND, DWORD, DWORD));
	MYFUNC *AnimateWindow;
	AnimateWindow = (MYFUNC*)::GetProcAddress (hInst, "AnimateWindow");
	AnimateWindow (this->m_hWnd, 1000, dwStyle);
	Invalidate ();
	FreeLibrary (hInst);

	////////////////////////////////////////////////////
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

/*****************************
*Create date : 2013/7/10
*Use for : 当Windows或应用程序请求重画应用程序窗口的一部分时，框架调用这个成员函数
*Function Name : OnPaint
*****************************/

void CFiveInLineDlg::OnPaint() 
{	
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);		
	}
	else
	{
		CPaintDC dc (this);
		CDC dcMem;
		dcMem.CreateCompatibleDC (&dc);

		CRect rect;
		GetClientRect (&rect);

		BITMAP bitMap;
		m_bmpBackGround.GetBitmap (&bitMap);
		//载入背景图片
		CBitmap *pbmpOld = dcMem.SelectObject (&m_bmpBackGround);
		dc.StretchBlt (0, 0, rect.Width (), rect.Height (),	&dcMem, 0, 0, bitMap.bmWidth, bitMap.bmHeight, SRCCOPY);
	}
}

/*****************************
*Create date : 2013/7/10
*Use for : 关闭窗口
*Function Name : OnClose()
*****************************/

void CFiveInLineDlg::OnClose()
{
	exit(0);
}

/*****************************
*Create date : 2013/7/10
*Use for : 进入游戏界面的开始游戏按钮响应函数
*Function Name : OnStartgame
*****************************/

void CFiveInLineDlg::OnStartgame() 
{
	// TODO: Add your control notification handler code here
	mciSendString("close .\\res\\aotemao.mp3", NULL, 0, NULL);	 //插入音乐
	this->ShowWindow(SW_HIDE);									 // 关闭父对话框

	CGameChooseDlg dlg;											//打开游戏界面
	dlg.DoModal();
}
