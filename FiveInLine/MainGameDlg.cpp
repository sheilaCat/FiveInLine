// MainGameDlg.cpp : implementation file
//

#include "stdafx.h"
#include "FiveInLine.h"
#include "MainGameDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMainGameDlg dialog


CMainGameDlg::CMainGameDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CMainGameDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CMainGameDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CMainGameDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CMainGameDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CMainGameDlg, CDialog)
	//{{AFX_MSG_MAP(CMainGameDlg)
	ON_WM_PAINT()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMainGameDlg message handlers
/////////引入对话框打开与关闭效果/////////////////
#define AW_CENTER                   0x00000010		//动画
#define AW_HIDE                     0x00010000		//隐藏
/////////////////////////////////////////////////
BOOL CMainGameDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();

	

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
	m_bmpBackGround.LoadBitmap (IDB_BITMAPMAINBG);

	//Step 8. 关联按钮和与之对应的成员变量
	//step 9. 加载按钮图片
//	m_bmpbtnClose.LoadBitmaps (IDB_BITMAPCLOSENORMAL,
//		IDB_BITMAPDOWN);
//	m_bmpbtnTwoState.LoadBitmaps (IDB_BITMAPONNORMAL,
//		IDB_BITMAPONDOWN);
	
//	m_bEnable = TRUE;
/**
	m_csStatic1.SubclassDlgItem (IDC_STATIC1, this);
	m_csTwoState.SubclassDlgItem (IDC_STATIC2, this);
	m_csAttribute.SubclassDlgItem (IDC_STATIC3, this);*/
	m_csAttribute.SetTextColor (RGB (255, 0, 0));
	//]]

	/////////////使用另一种更便于实现的方法更换按钮位图/////////////

	m_bmpbtnMusic.LoadBitmaps(IDB_BITMAPMUSICOFF,IDB_BITMAPMUSICON);
	m_bmpbtnMusic.SubclassDlgItem(IDC_BUTMUSIC,this);
	m_bmpbtnMusic.SizeToContent();

	m_bmpbtnAgain.LoadBitmaps(IDB_BITMAPAGAIN1,IDB_BITMAPAGAIN2);
	m_bmpbtnAgain.SubclassDlgItem(IDC_BUTAGAIN,this);
	m_bmpbtnAgain.SizeToContent();

	m_bmpbtnRegret.LoadBitmaps(IDB_BITMAPREGRET1,IDB_BITMAPREGRET2);
	m_bmpbtnRegret.SubclassDlgItem(IDC_BUTREGRET,this);
	m_bmpbtnRegret.SizeToContent();

	m_bmpbtnExit.LoadBitmaps(IDB_BITMAPEXIT1,IDB_BITMAPEXIT2);
	m_bmpbtnExit.SubclassDlgItem(IDC_BUTEXIT,this);
	m_bmpbtnExit.SizeToContent();
///////////////////////////////////////////////////////////////
	
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

void CMainGameDlg::OnPaint() 
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

void CMainGameDlg::OnLButtonDown(UINT nFlags, CPoint point)
{
	PostMessage (WM_NCLBUTTONDOWN, HTCAPTION, MAKELPARAM (point.x, point.y));
	CDialog::OnLButtonDown (nFlags, point);
}
