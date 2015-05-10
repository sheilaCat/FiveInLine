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
	DDX_Control(pDX, IDC_TWOSTATE, m_bmpbtnTwoState);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CFiveInLineDlg, CDialog)
	//{{AFX_MSG_MAP(CFiveInLineDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_TWOSTATE, OnTwoState)
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

BOOL CFiveInLineDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	//设置窗口阴影
	SetClassLong(this->m_hWnd, GCL_STYLE, GetClassLong(this->m_hWnd, GCL_STYLE) | 0x00020000);

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	//[[ Step 1. 修改窗口样式
	ModifyStyle (WS_CAPTION, WS_MINIMIZEBOX, SWP_DRAWFRAME);
	SetWindowText (_T ("asdf"));
	
	SetIcon (m_hIcon, TRUE);
	SetIcon (m_hIcon, FALSE);

	//Step 2.load bitmap
	m_bmpBackGround.LoadBitmap (IDB_BITMAPBACKGROUND);

	//Step 8. 关联按钮和与之对应的成员变量
	//step 9. 加载按钮图片
	m_bmpbtnClose.LoadBitmaps (IDB_BITMAPCLOSENORMAL,
		IDB_BITMAPDOWN);
	m_bmpbtnTwoState.LoadBitmaps (IDB_BITMAPONNORMAL,
		IDB_BITMAPONDOWN);

/////////////使用另一种更便于实现的方法更换按钮位图/////////////

	m_bmpbtnStart.LoadBitmaps(IDB_BITMAPSTARTUP,IDB_BITMAPSTARTDOWN);
	m_bmpbtnStart.SubclassDlgItem(IDC_STARTGAME,this);
	m_bmpbtnStart.SizeToContent();

///////////////////////////////////////////////////////////////

	
	m_bEnable = TRUE;

/**	m_csStatic1.SubclassDlgItem (IDC_STATIC1, this);
	m_csTwoState.SubclassDlgItem (IDC_STATIC2, this);
	m_csAttribute.SubclassDlgItem (IDC_STATIC3, this);*/
	m_csAttribute.SetTextColor (RGB (255, 0, 0));
	//]]
	
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

void CFiveInLineDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CFiveInLineDlg::OnPaint() 
{	if (IsIconic())
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
		//Step 3. remove the follow statement
		//	CDialog::OnPaint();	
		//Step 4. Create memory-DC
		CPaintDC dc (this);
		CDC dcMem;
		dcMem.CreateCompatibleDC (&dc);

		CRect rect;
		GetClientRect (&rect);

		BITMAP bitMap;
		m_bmpBackGround.GetBitmap (&bitMap);
		//Step 5. load bitmap to dlg
		CBitmap *pbmpOld = dcMem.SelectObject (&m_bmpBackGround);
		dc.StretchBlt (0, 0, rect.Width (), rect.Height (),
			&dcMem, 0, 0, bitMap.bmWidth, 
			bitMap.bmHeight, SRCCOPY);
		//Step 6, add btn and other wnd
		//step 7. add ColorBtn Class.
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CFiveInLineDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

/*****************************
*Create date : 2013/7/10
*Use for : 关闭窗口
*Name : OnClose()
*****************************/

void CFiveInLineDlg::OnClose()
{/**
	DWORD dwStyle = AW_CENTER;
	HINSTANCE hInst = LoadLibrary ("User32.DLL"); 
	typedef BOOL(WINAPI MYFUNC (HWND, DWORD, 		DWORD));
	MYFUNC* AnimateWindow;
	AnimateWindow=(MYFUNC *)::GetProcAddress (hInst,"AnimateWindow");
	AnimateWindow(this->GetSafeHwnd(),500, AW_HIDE | dwStyle);
	FreeLibrary(hInst);
	*/
	CDialog::OnCancel ();
}

/**************************
*Create date : 2013/7/10
*Use for : 更换鼠标图标
*Name : OnSetCursor
*************************/

BOOL CFiveInLineDlg::OnSetCursor(CWnd *pWnd, UINT nHitTest, UINT message)
{
	if (IDC_CLOSEBTN == pWnd->GetDlgCtrlID ())
	{
		SetCursor (AfxGetApp ()->LoadCursor (IDC_HAND));
		return TRUE;
	}

	SetCursor (AfxGetApp ()->LoadCursor (IDC_NORMAL));
	return TRUE;

}

void CFiveInLineDlg::OnLButtonDown(UINT nFlags, CPoint point)
{
	PostMessage (WM_NCLBUTTONDOWN, HTCAPTION, MAKELPARAM (point.x, point.y));
	CDialog::OnLButtonDown (nFlags, point);
}
/**************************
*Create date : 2013/7/10
*Use for : 开关音乐
*Name : OnTwoState
*************************/

void CFiveInLineDlg::OnTwoState()
{
	if (m_bEnable)
	{
		m_bmpbtnTwoState.LoadBitmaps (IDB_BITMAPOFFNORMAL,
			IDB_BITMAPOFFDOWN);
		mciSendString("play .\\res\\aotemao.mp3 repeat", NULL, 0, NULL);
		m_bEnable = FALSE;
		m_bmpbtnTwoState.RedrawWindow ();
	}
	else
	{
		m_bmpbtnTwoState.LoadBitmaps (IDB_BITMAPONNORMAL,
			IDB_BITMAPONDOWN);
		mciSendString("close .\\res\\aotemao.mp3", NULL, 0, NULL);
		m_bEnable = TRUE;
		m_bmpbtnTwoState.RedrawWindow ();
	}
}

void CFiveInLineDlg::OnStartgame() 
{
	// TODO: Add your control notification handler code here
		//进入游戏界面的开始游戏按钮
	// TODO: Add your control notification handler code here
	mciSendString("close .\\res\\aotemao.mp3", NULL, 0, NULL);
	this->ShowWindow(SW_HIDE);  // 关闭父对话框
	CGameChooseDlg dlg;
	dlg.DoModal();

	/*if(dlg.DoModal()==IDCANCEL)
	{
		this->ShowWindow(SW_SHOW);
	}*/
}
