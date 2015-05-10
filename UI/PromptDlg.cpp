// PromptDlg.cpp : implementation file
//

#include "stdafx.h"
#include "..\FiveInLine.h"
#include "PromptDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CPromptDlg dialog


CPromptDlg::CPromptDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CPromptDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CPromptDlg)
	//}}AFX_DATA_INIT
}


void CPromptDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CPromptDlg)
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CPromptDlg, CDialog)
	//{{AFX_MSG_MAP(CPromptDlg)
	ON_WM_PAINT()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPromptDlg message handlers

void CPromptDlg::Draw(int x, int y, UINT bitmap, CDC *pDC)
{
	//	装载图片
	CBitmap m_bmp;
	m_bmp.LoadBitmap(bitmap);
	//	创建画布，比如要在窗口显示，则pDC为窗口句柄 
	CDC dc;
	dc.CreateCompatibleDC(pDC); 
	//	下面其实是两步，可以单独使用dc.SelectObject(&m_bmp);,也就将位图选到dc中 
	// CBitmap *pOldbmp=是保存画刷，和函数最后的恢复画刷对应 
	//	保存画刷和恢复画刷可以不用，但会造成资源泄漏。 
	CBitmap *pOldbmp=dc.SelectObject(&m_bmp); 
	//	创建bm，用来获取图片信息，这里是为了获取图片尺寸 
	BITMAP bm;
	m_bmp.GetObject(sizeof(BITMAP),&bm); 
	//	画图 
	if(IDB_BITMAPBOARD==bitmap)//画棋盘 
	//if(IDB_BITMAPMAINBG==bitmap)
		pDC->BitBlt(x,y,bm.bmWidth,bm.bmHeight,&dc,0,0,SRCCOPY); 
	else 
	{//	每个图片里有4X4个棋子，只要画出一个就行了 
		int w=bm.bmWidth/4; 
		int h=bm.bmHeight/4; 
		TransparentBlt(pDC->m_hDC,x,y,w,h,dc.m_hDC,0,0,w,h,RGB(255,255,255)); 
	} 
	dc.SelectObject(pOldbmp);//恢复画刷 
}

void CPromptDlg::OnPaint() 
{
/**	CPaintDC dc(this); // device context for painting
	
	// TODO: Add your message handler code here
	CDC *pDC = GetDC();
	if(m_iState == 1)					//	悔棋
		Draw(0,0,IDB_BITMAPHUIQI,pDC);
	else if(m_iState == 2)				//	新游戏
		Draw(0,0,IDB_BITMAPZAILAI,pDC);
	// Do not call CDialog::OnPaint() for painting messages*/


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
	
}

BOOL CPromptDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	ModifyStyle (WS_CAPTION, WS_MINIMIZEBOX, SWP_DRAWFRAME);
	SetWindowText (_T ("asdf"));

	if(m_iState == 1) // 悔棋
	m_bmpBackGround.LoadBitmap(IDB_BITMAPHUIQI);
	else if(m_iState == 2)
	m_bmpBackGround.LoadBitmap(IDB_BITMAPZAILAI);


	m_bmpbtnOK.LoadBitmaps(IDB_BITMAPTIPBTN1,IDB_BITMAPTIPBTN2);
	m_bmpbtnOK.SubclassDlgItem(IDOK,this);
	m_bmpbtnOK.SizeToContent();

	m_bmpbtnCancel.LoadBitmaps(IDB_BITMAPTIPBTN3,IDB_BITMAPTIPBTN4);
	m_bmpbtnCancel.SubclassDlgItem(IDCANCEL,this);
	m_bmpbtnCancel.SizeToContent();

	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}
