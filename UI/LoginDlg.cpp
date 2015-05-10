// LoginDlg.cpp : implementation file
//

#include "stdafx.h"
#include "..\FiveInLine.h"
#include "..\UI\MainGameDlg.h"
#include "LoginDlg.h"
#include <mmsystem.h>               //音乐
#pragma comment(lib, "winmm.lib")   //音乐

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CLoginDlg dialog


CLoginDlg::CLoginDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CLoginDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CLoginDlg)
	m_csName = _T("");
	//}}AFX_DATA_INIT
}


void CLoginDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CLoginDlg)
	DDX_Control(pDX, IDC_IPADDRESS, m_ipAddress);
	DDX_Text(pDX, IDC_NAME, m_csName);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CLoginDlg, CDialog)
	//{{AFX_MSG_MAP(CLoginDlg)
	ON_WM_PAINT()
	ON_BN_CLICKED(IDC_BUTEXIT, OnButexit)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CLoginDlg message handlers

void CLoginDlg::OnOK() 
{
	// TODO: Add extra validation here
	UpdateData(true);

	//去除空白字符
	if(m_csName == "")
	{
		PlaySound("res\\system.wav", AfxGetInstanceHandle(), SND_FILENAME | SND_ASYNC | SND_NODEFAULT);
		MessageBox("昵称不能为空！","提示");
	}
	else if(m_csName.Find("~")>=0||m_csName.Find("-")>=0)
	{
		PlaySound("res\\system.wav", AfxGetInstanceHandle(), SND_FILENAME | SND_ASYNC | SND_NODEFAULT);
		MessageBox("昵称不能包含非法字符！","提示");
	}
	else if(m_csName.GetAt(0)<='9'&&m_csName.GetAt(0)>='0')
	{
		PlaySound("res\\system.wav", AfxGetInstanceHandle(), SND_FILENAME | SND_ASYNC | SND_NODEFAULT);
		MessageBox("昵称不能以数字开头！","提示");
	}
	else
	{
		m_csName.TrimLeft();
		m_csName.TrimRight();

		// 获得所写的IP地址
		BYTE nb0, nb1, nb2, nb3;
		m_ipAddress.GetAddress(nb0, nb1, nb2, nb3);

		m_csIPAddress.Format("%d.%d.%d.%d", nb0, nb1, nb2, nb3);

		this->ShowWindow(SW_HIDE);  // 关闭父对话框

		CMainGameDlg dlg;

		dlg.m_iNet = 1;

		dlg.m_csName = m_csName;

		dlg.m_csIPAddress = m_csIPAddress;

		dlg.DoModal();

		CDialog::OnOK();
	}
}

void CLoginDlg::OnCancel() 
{
	// TODO: Add extra cleanup here
	
	CDialog::OnCancel();
}

BOOL CLoginDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();

	ModifyStyle (WS_CAPTION, WS_MINIMIZEBOX, SWP_DRAWFRAME);
	SetWindowText (_T ("asdf"));

	m_bmpBackGround.LoadBitmap(IDB_BITMAPLOGINBG);

	m_bmpbtnGo.LoadBitmaps(IDB_BITMAPLOGINBTN2,IDB_BITMAPLOGINBTN1);
	m_bmpbtnGo.SubclassDlgItem(IDOK,this);
	m_bmpbtnGo.SizeToContent();

	m_bmpbtnExit.LoadBitmaps(IDB_BITMAPEXITLOG,IDB_BITMAPEXITLOG);
	m_bmpbtnExit.SubclassDlgItem(IDC_BUTEXIT,this);
	m_bmpbtnExit.SizeToContent();
	// TODO: Add extra initialization here

	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CLoginDlg::OnPaint() 
{
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

//DEL HBRUSH CLoginDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor) 
//DEL {
//DEL 	HBRUSH hbr = CDialog::OnCtlColor(pDC, pWnd, nCtlColor);
//DEL      // TODO:  m_editMinute 和 m_editYear 对应于控件EditBox
//DEL /**     if( pWnd->GetSafeHwnd() == m_editMinute.GetSafeHwnd() ||
//DEL          pWnd->GetSafeHwnd() == m_editYear.GetSafeHwnd() )
//DEL      {*/
//DEL          //将背景色设为白色
//DEL          static HBRUSH   hbrEdit = ::CreateSolidBrush( RGB(217,239,248) );
//DEL          pDC->SetBkMode( TRANSPARENT );
//DEL          return hbrEdit;
//DEL   //   }
//DEL      // TODO:
//DEL      return hbr;
//DEL }

void CLoginDlg::OnButexit() 
{
	// TODO: Add your control notification handler code here
	exit(0);
}
