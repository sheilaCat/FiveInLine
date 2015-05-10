// GameChooseDlg.cpp : implementation file
//

#include "stdafx.h"
#include "FiveInLine.h"
#include "GameChooseDlg.h"
#include "UI\LoginDlg.h"
#include "UI\MainGameDlg.h"
#include <mmsystem.h>               //ÒôÀÖ
#pragma comment(lib, "winmm.lib")   //ÒôÀÖ

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CGameChooseDlg dialog


CGameChooseDlg::CGameChooseDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CGameChooseDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CGameChooseDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CGameChooseDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CGameChooseDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CGameChooseDlg, CDialog)
	//{{AFX_MSG_MAP(CGameChooseDlg)
	ON_WM_PAINT()
	ON_BN_CLICKED(IDC_CLOSEBTN, OnClosebtn)
	ON_BN_CLICKED(IDC_SINGLEGAME, OnSingle)
	ON_BN_CLICKED(IDC_DOUBLEGAME, OnDouble)
	ON_BN_CLICKED(IDC_CREATE, OnCreate)
	ON_BN_CLICKED(IDC_CONNECT, OnConnect)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CGameChooseDlg message handlers

BOOL CGameChooseDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();

	ModifyStyle (WS_CAPTION, WS_MINIMIZEBOX, SWP_DRAWFRAME);
	SetWindowText (_T ("asdf"));

	m_bmpBackGround.LoadBitmap(IDB_BITMAPBACKGROUND);
	
	// TODO: Add extra initialization here
	m_bmpbtnSingle.LoadBitmaps(IDB_BITMAPSINGLE1,IDB_BITMAPSINGLE2);
	m_bmpbtnSingle.SubclassDlgItem(IDC_SINGLEGAME,this);
	m_bmpbtnSingle.SizeToContent();

	m_bmpbtnDouble.LoadBitmaps(IDB_BITMAPDOUBLE1,IDB_BITMAPDOUBLE2);
	m_bmpbtnDouble.SubclassDlgItem(IDC_DOUBLEGAME,this);
	m_bmpbtnDouble.SizeToContent();

	m_bmpbtnConnect.LoadBitmaps(IDB_BITMAPCONNECT1,IDB_BITMAPCONNECT2);
	m_bmpbtnConnect.SubclassDlgItem(IDC_CONNECT,this);
	m_bmpbtnConnect.SizeToContent();

	m_bmpbtnCreate.LoadBitmaps(IDB_BITMAPCREATE1,IDB_BITMAPCREATE2);
	m_bmpbtnCreate.SubclassDlgItem(IDC_CREATE,this);
	m_bmpbtnCreate.SizeToContent();

	m_bmpbtnClose.LoadBitmaps(IDB_BITMAPCLOSENORMAL,IDB_BITMAPDOWN);
	m_bmpbtnClose.SubclassDlgItem(IDC_CLOSEBTN,this);
	m_bmpbtnClose.SizeToContent();


	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CGameChooseDlg::OnPaint() 
{
	/**	if (IsIconic())
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
	{*/
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
//	}
}

void CGameChooseDlg::OnClosebtn() 
{
	// TODO: Add your control notification handler code here
	exit(0);
}

void CGameChooseDlg::OnSingle() 
{
	// TODO: Add your control notification handler code here	
	this->ShowWindow(SW_HIDE); 
	CMainGameDlg dlg;
	dlg.m_isSingle=true;
	if(dlg.DoModal()==IDCANCEL)
		this->ShowWindow(SW_SHOW); 

	//CDialog::OnOK();
}

void CGameChooseDlg::OnDouble() 
{
	// TODO: Add your control notification handler code here	
	this->ShowWindow(SW_HIDE);
	CMainGameDlg dlg;
	dlg.m_isSingle = false;
	if(dlg.DoModal()==IDCANCEL)
		this->ShowWindow(SW_SHOW); 
	//CDialog::OnOK();
}

void CGameChooseDlg::OnCreate() 
{
	// TODO: Add your control notification handler code here	
	this->ShowWindow(SW_HIDE); 
	CMainGameDlg dlg;
	dlg.m_iNet = 2;
	if(dlg.DoModal()==IDCANCEL)
		this->ShowWindow(SW_SHOW); 
	//CDialog::OnOK();
}

void CGameChooseDlg::OnConnect() 
{
	// TODO: Add your control notification handler code here
	this->ShowWindow(SW_HIDE); 
	CLoginDlg dlg;
	if(dlg.DoModal()==IDCANCEL)
		this->ShowWindow(SW_SHOW); 
	//CDialog::OnOK();
}
