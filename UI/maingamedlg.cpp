// MainGameDlg.cpp : implementation file
//

#include "stdafx.h"
#include "..\Logic\Statistics.h"
#include "..\Data\ChatSocket.h"
#include "..\FiveInLine.h"
#include "MainGameDlg.h"
#include "EndDlg.h"
#include "PromptDlg.h"
#include <mmsystem.h>               //音乐
#pragma comment(lib, "winmm.lib")   //音乐
#include <wingdi.h>
#include <cmath>
#include <stdlib.h>
#include <afxsock.h>
#pragma comment(lib,"ws2_32.lib")
#pragma comment(lib,"msimg32.lib")







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
	m_csALLMSG = _T("");
	m_csMSG = _T("");
	
	//}}AFX_DATA_INIT
	AfxInitRichEdit();
}


void CMainGameDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CMainGameDlg)
	DDX_Control(pDX, IDC_RICHEDIT, m_edALLMSG);
	DDX_Text(pDX, IDC_RICHEDIT, m_csALLMSG);
	DDX_Text(pDX, IDC_EDIT_MSG, m_csMSG);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CMainGameDlg, CDialog)
	//{{AFX_MSG_MAP(CMainGameDlg)
	ON_WM_PAINT()
	ON_BN_CLICKED(IDC_BUTEXIT, OnButexit)
	ON_BN_CLICKED(IDC_BUTAGAIN, OnButagain)
	ON_BN_CLICKED(IDC_BUTMUSIC, OnButmusic)
	ON_BN_CLICKED(IDC_BUTREGRET, OnButregret)
	ON_BN_CLICKED(IDC_BUTTON_SEND, OnButtonSend)
	ON_WM_LBUTTONDOWN()
	ON_WM_CTLCOLOR()
	ON_BN_CLICKED(IDC_CANCEL, OnCancel)
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
	//SetWindowText (_T ("asdf"));
	
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





//////////////////////////////////////////////////////////////////////////////////
	/////////////使用另一种更便于实现的方法更换按钮位图/////////////
//////////////////////////////////////////////////////////////////////////////////

	m_bmpbtnMusic.SubclassDlgItem(IDC_BUTMUSIC,this);
	//m_bmpbtnMusic.LoadBitmaps(IDB_BITMAPMUSICOFF,IDB_BITMAPMUSICON);
	m_bmpbtnMusic.LoadBitmaps(IDB_BITMAPMUSICOFF);
	
	m_bmpbtnMusic.SizeToContent();



	m_bmpbtnAgain.SubclassDlgItem(IDC_BUTAGAIN,this);
	m_bmpbtnAgain.LoadBitmaps(IDB_BITMAPAGAIN1,IDB_BITMAPAGAIN2);
	
	m_bmpbtnAgain.SizeToContent();



	m_bmpbtnRegret.SubclassDlgItem(IDC_BUTREGRET,this);
	m_bmpbtnRegret.LoadBitmaps(IDB_BITMAPREGRET1,IDB_BITMAPREGRET2);
	
	m_bmpbtnRegret.SizeToContent();



	m_bmpbtnExit.SubclassDlgItem(IDC_BUTEXIT,this);
	m_bmpbtnExit.LoadBitmaps(IDB_BITMAPEXIT1,IDB_BITMAPEXIT2);
	
	m_bmpbtnExit.SizeToContent();



	m_bmpbtnSend.SubclassDlgItem(IDC_BUTTON_SEND,this);
	m_bmpbtnSend.LoadBitmaps(IDB_BITMAPSEND1,IDB_BITMAPSEND2);
	
	m_bmpbtnSend.SizeToContent();

	m_bmpbtnExitReal.SubclassDlgItem(IDC_CANCEL,this);
	m_bmpbtnExitReal.LoadBitmaps(IDB_BITMAPEXITGAME,IDB_BITMAPEXITGAME);
	
	m_bmpbtnExitReal.SizeToContent();

//////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////

	




//////////////////////////////////////////////////////////////////////////////////
	//////////////////////打开与关闭窗口特效//////////////////
//////////////////////////////////////////////////////////////////////////////////
 	CenterWindow ();	
	DWORD dwStyle = AW_CENTER;
	HINSTANCE hInst = LoadLibrary("User32.DLL"); 
	
	typedef BOOL (WINAPI MYFUNC (HWND, DWORD, DWORD));
	MYFUNC *AnimateWindow;
	AnimateWindow = (MYFUNC*)::GetProcAddress (hInst, "AnimateWindow");
	AnimateWindow (this->m_hWnd, 0, dwStyle);
	Invalidate ();
	FreeLibrary (hInst); 
//////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////
	




//////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////
/////功能区

	for(int i = 0;i < 15;i++)
		for(int j = 0;j < 15;j++)
		{
			chess[i][j] = 0;			//	初始化棋盘数组，1为黑棋，2为白棋，0为没有棋子
		}
	m_iTheEnd = 0;						//	初始化为未结束游戏
	m_isAgreed = false;					//	初始化为拒绝悔棋或新游戏
	m_iPlayer = 2;						//	初始化为白棋先下
	m_iSuccess = 0;						//	初始化为连接不成功
	//m_iMusic =	0;						//	初始化音乐为关的状态
	//m_isSingle = true;					//	初始化为单人游戏
/////功能区
//////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////





//////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////
/////网络区
	AfxSocketInit();


	//客户端进行的操作
	if(m_iNet==1)
	{
		SetWindowText(" 五子棋--玩家客户端 ");									//	设置窗口标题


		m_pSocket = new CClientSocket(this);								// 创建Socket套接字


		if(!m_pSocket->Create()||!m_pSocket->Connect(m_csIPAddress, 7000))	//	连接到服务器端
		{
			delete m_pSocket;
			m_pSocket = NULL;
			MessageBox(" 建立连接失败！");
			return FALSE;
		}

		// 向服务器端发送一个注册成功的消息
		CString csLogin = "Login~";
		m_pSocket->Send(csLogin, csLogin.GetLength());

	}
	

	//服务器端进行的操作
	else if(m_iNet==2)
	{

		m_pSrvSocket = new CSrvSocket(this);									// 创建Socket套接字

		
		// 创建服务
		SetWindowText(" 五子棋--服务器端 ");

		if (!m_pSrvSocket->Create(7000))										//	绑定端口
		{
			delete m_pSrvSocket;
			m_pSrvSocket = NULL;
			MessageBox("绑定失败!");
			return FALSE;
		}

		
		m_pSrvSocket->Listen();													// 启动监听
	}

/////网络区
//////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////
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

		CDC *pDC = GetDC();
		Draw(160,10,IDB_BITMAPBOARD,pDC);
		for(int i = 0;i<15;i++)
			for(int j = 0;j<15;j++)
			{
				if(chess[i][j]==2)
					Draw(j*33.5+160,i*33.5+10,IDB_BITMAPWHITE,pDC);
				else if(chess[i][j]==1)
					Draw(j*33.5+160,i*33.5+10,IDB_BITMAPBLACK,pDC);
			}
	}
}

//	点击鼠标触发事件
void CMainGameDlg::OnLButtonDown(UINT nFlags, CPoint point)
{
	PostMessage (WM_NCLBUTTONDOWN, HTCAPTION, MAKELPARAM (point.x, point.y));

	//	若未结束游戏，则对单击事件进行响应
	if(m_iTheEnd==0)
	{
		if(point.x>160&&point.x<650&&point.y>10&&point.y<510)				//	判断鼠标是否点击在有效区内
		{
			//玩家落子
			
			//	计算出鼠标点击位置所对应的棋盘坐标
			PlaySound("res\\luozisy.wav", AfxGetInstanceHandle(), SND_FILENAME | SND_ASYNC | SND_NODEFAULT);   //落子音效
			int j = (int)((point.x-160)/33.5);
			int i = (int)((point.y-10)/33.5);
			int x = (int)(j*33.5+160);
			int y = (int)(i*33.5+10);


			CDC *pDC=GetDC();//获取当前设备句柄

			//当前位置无棋子时，则进行操作
			if(chess[i][j] == 0)
			{

				/*CString cs;
				cs.Format("%d,%d",i,j);
				MessageBox(cs,"结束");*/

//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
//////////////////局域网对战模块
				if(m_iSuccess==1)												//	若连接成功，则进行响应
				{
					if(m_iNet==2&&m_iPlayer==2)									//	判断是否轮到当前棋手
					{
						Draw(x,y,IDB_BITMAPWHITE,pDC);							//	画出棋子
						chess[i][j] = 2;										//	将棋盘数组的该位置设置为白棋标记"2"
						//step.point2.x=i;
						//step.point2.y=j;

						/////////////////////////////
						//	记录当前落子位置，并入栈
						step.x=i;
						step.y=j;
						m_stack.push(step);
						/////////////////////////////
						

						//	将落子信息连接成字符串向所有的客户端发送
						CString x;
						x.Format("%d",i);
						CString y;
						y.Format("%d",j);
						x = x+"~"+y;

						POSITION pPos = m_listClients.GetHeadPosition();		//	获得列表中第一个客户端位置
						
						while(pPos)
						{
							CChatSocket* pCur = m_listClients.GetAt(pPos);
							//csMsgTo = "管理员~" + m_strMSG;
							pCur->Send(x, x.GetLength());						//	发送信息
							//m_strAllMSG += "你对 " + pCur->m_strNick + " 说: " + m_strMSG + "\r\n";
							
							m_listClients.GetNext(pPos);						//	获得列表中下一个客户端位置
						}

						//	判断是否已经获胜
						if(m_statis.isWin(chess,i,j))
						{
							m_iTheEnd = 1;
							CEndDlg dlg;
							dlg.m_iIsWin=1;
							dlg.DoModal();
							return;
						}
						m_iPlayer = 1;											//	换棋手
					}	//	if(m_iNet==2&&m_iPlayer==2)		END

					//	客户端进行的操作
					else if(m_iNet==1&&m_iPlayer==1)
					{
						Draw(x,y,IDB_BITMAPBLACK,pDC);							//	在当前位置画出黑棋
						chess[i][j] = 1;										//	将棋盘数组的该位置设置为黑棋标记"1"
						//step.point1.x=i;
						//step.point1.y=j;



						/////////////////////////////
						//	记录当前落子位置，并入栈
						step.x=i;
						step.y=j;
						m_stack.push(step);
						/////////////////////////////


						/////////////////////////////////////////////
						//	将当前的落子信息连接成字符串向服务器发送
						/////////////////////////////////////////////
						CString x;
						x.Format("%d",i);
						CString y;
						y.Format("%d",j);
						x = x+"~"+y;
						m_pSocket->Send(x, x.GetLength());
						/////////////////////////////////////////////
						/////////////////////////////////////////////



						/////////////////////////////////////////////
						//	判断是否已经获胜/////////////////////////
						/////////////////////////////////////////////
						if(m_statis.isWin(chess,i,j))
						{
							m_iTheEnd = 1;
					//		MessageBox("黑棋赢！","结束");

							//	向服务器端发送对方已经输了的信息
							//CString lose = "Lose~";
							//m_pSocket->Send(lose, lose.GetLength());
							CEndDlg dlg;
							dlg.m_iIsWin=1;
							dlg.DoModal();
							return;
						}
						/////////////////////////////////////////////
						/////////////////////////////////////////////

						m_iPlayer = 2;													//	换棋手
					}//else if(m_iNet==1&&m_iPlayer==1)	END
				}//if(m_iSuccess==1)  END
//////////////////局域网对战模块
//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////


				



//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
//////////////////人机对战、人人对战模块
				if(m_iNet==0||m_iSuccess==0)											//	判断是否为单人模式
				{
					if(m_iPlayer==2)
					{

						//此段代码用于测试各点打分是否正确
						/*CString cs;
						cs.Format("%d",m_statis.getScore(chess,i,j));
						MessageBox(cs,"结束");*/



						Draw(x,y,IDB_BITMAPWHITE,pDC);									//	在当前位置画出白棋
						chess[i][j] = 2;												//	将棋盘数组的该位置设置为白棋标记"2"


						/////////////////////////////
						//	记录当前落子信息，并入栈
						step.x=i;
						step.y=j;
						m_stack.push(step);
						/////////////////////////////
						/////////////////////////////

						m_iPlayer=1;													//	更换棋手

					}
					
					//	if(m_isSingle)													
					else if(!m_isSingle)
					{
						Draw(x,y,IDB_BITMAPBLACK,pDC);									//	在当前位置画出黑棋
						chess[i][j] = 1;												//	将棋盘数组的该位置设置为黑棋标记"2"


						/////////////////////////////
						//	记录当前落子信息，并入栈
						step.x=i;
						step.y=j;
						m_stack.push(step);
						/////////////////////////////
						/////////////////////////////

						m_iPlayer=2;													//	更换棋手

					}




					////////////////////////////////////////////////////
					//	判断是否结束游戏////////////////////////////////
					////////////////////////////////////////////////////
					if(m_statis.isWin(chess,i,j))
					{
						m_iTheEnd = 1;
						//	MessageBox("白棋赢！","结束");
						
						CEndDlg dlg;
						dlg.m_iIsWin=1;
						dlg.DoModal();
						return;
					}
					////////////////////////////////////////////////////
					////////////////////////////////////////////////////
					
					

					//计算机落子
					if(m_iPlayer==1&&m_isSingle)											//	若为单人游戏，则计算机落子
					{
						m_iPlayer=2;														//	更换棋手
						int max=0,score;
						int k,m;
						//循环遍历棋盘，更新每个空位置的分数，记录当前最高分值位置
						for(k=0;k<15;k++)
						{
							for(m=0;m<15;m++)
							{
								score=abs(m_statis.getScore(chess,k,m))>m_statis.m_iCpuScore[k][m]?abs(m_statis.getScore(chess,k,m)):m_statis.m_iCpuScore[k][m];
								if(chess[k][m]==0&&score>=max)
								{
									max=score;
									i=k;
									j=m;
								}
							}
						}


						step.x=i;
						step.y=j;
						m_stack.push(step);

						///////////////////////////////////////////////////
						//	将当前棋子位置转换成坐标
						x=(int)(j*33.5+160);
						y=(int)(i*33.5+10);

						Draw(x,y,IDB_BITMAPBLACK,pDC);									//	画出白棋
						chess[i][j] = 1;												//	更新棋盘数组
						


						//此段代码用于测试各点打分是否正确
						/*CString cs;
						cs.Format("%d",m_statis.getScore(chess,i,j));
						MessageBox(cs,"结束");*/

						///////////////////////////////////////////////////
						//	判断计算机是否胜利
						///////////////////////////////////////////////////
						if(m_statis.isWin(chess,i,j))
						{
							m_iTheEnd = 1;
							//	MessageBox("黑棋赢！","结束");
							CEndDlg dlg;
							dlg.m_iIsWin=0;
							dlg.DoModal();
						}
						///////////////////////////////////////////////////
						///////////////////////////////////////////////////



					}// if(m_iPlayer==1)    END
				}// if(m_iNet==0||m_iSuccess==0)   END

//////////////////人机对战模块
//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

			}//	if(chess[i][j] == 0)	END
		}
	}

	CDialog::OnLButtonDown(nFlags, point);
}

void CMainGameDlg::OnButexit() 
{
	// TODO: Add your control notification handler code here
	//exit(0);
	CDialog::OnCancel();
}


///////////////////////////////////////////////////
//	新游戏按钮事件响应
///////////////////////////////////////////////////
void CMainGameDlg::OnButagain() 
{
	// TODO: Add your control notification handler code here

	//	若非网络模式或对方已经同意新游戏，则直接进行操作
	if(!m_iSuccess||m_iNet==0||m_isAgreed)
	{
		m_iPlayer = 2;
		m_statis.Renew(chess);											//	将棋盘记录清空
		m_stack.clear();
		m_iTheEnd=0;
		Invalidate(true);												//	刷新界面


		//	若为对方同意新游戏，则将判定记录取反
		if(m_isAgreed)
		{
			m_isAgreed = !m_isAgreed;

			//	若当前为服务器端，则向每个客户端发送进行操作后的棋盘
			if(m_iNet==2)
			{
				//服务器每接收到一次消息，则向除玩家外的每一个客户端发送接收到的消息
				POSITION pPos = m_listClients.GetHeadPosition();
				m_listClients.GetNext(pPos);
				if(pPos)																//	若当前客户端非空
				{
					///////////////////////////////////////////////
					//	将当前棋盘信息连接成字符串信息
					///////////////////////////////////////////////
					CString send = "-~";
					CString cs;
					for(int i=0;i<15;i++)
					{
						for(int j = 0;j<15;j++)
						{
							cs.Format("%d",chess[i][j]);
							send = send + cs;
						}
					}
					///////////////////////////////////////////////
					///////////////////////////////////////////////


					///////////////////////////////////////////////
					//	循环遍历所有的客户端，并向其发送信息
					///////////////////////////////////////////////
					while(pPos)
					{
						CChatSocket* pCur = m_listClients.GetAt(pPos);
						//csMsgTo = "管理员~" + m_strMSG;
						pCur->Send(send, send.GetLength());
						m_listClients.GetNext(pPos);
					}
					///////////////////////////////////////////////
					///////////////////////////////////////////////
				}
			}
		}
	}

	///////////////////////////////////////////////////
	//	若当前操作对象为服务器，则进行操作
	///////////////////////////////////////////////////
	else if(m_iNet == 2)
	{
		POSITION pPos = m_listClients.GetHeadPosition();
			
		CChatSocket* pCur = m_listClients.GetAt(pPos);
		CString renew = "Renew~";
		pCur->Send(renew, renew.GetLength());
		
	}
	///////////////////////////////////////////////////
	///////////////////////////////////////////////////


	///////////////////////////////////////////////////
	//	若当前操作对象为客户端，则进行操作
	///////////////////////////////////////////////////
	else if(m_iNet == 1)
	{
		CString renew = "Renew~";
		m_pSocket->Send(renew, renew.GetLength());
	}
	///////////////////////////////////////////////////
	///////////////////////////////////////////////////
}
///////////////////////////////////////////////////
///////////////////////////////////////////////////







///////////////////////////////////////////////////
//	点击音乐播放按钮进行事件响应
///////////////////////////////////////////////////
void CMainGameDlg::OnButmusic() 
{
	// TODO: Add your control notification handler code here
	if (m_iMusic == 0)
	{
		m_bmpbtnMusic.LoadBitmaps (IDB_BITMAPMUSICON,
			IDB_BITMAPMUSICON);
		mciSendString("play .\\res\\cjmlbj.mp3 repeat", NULL, 0, NULL);
		m_iMusic = 1;
		m_bmpbtnMusic.RedrawWindow ();
	}
	else
	{
		m_bmpbtnMusic.LoadBitmaps (IDB_BITMAPMUSICOFF,
			IDB_BITMAPMUSICOFF);
		mciSendString("close .\\res\\cjmlbj.mp3", NULL, 0, NULL);
		m_iMusic = 0;
		m_bmpbtnMusic.RedrawWindow ();
	}
	
}
///////////////////////////////////////////////////
///////////////////////////////////////////////////






///////////////////////////////////////////////////
//	点击悔棋按钮进行事件响应
///////////////////////////////////////////////////
void CMainGameDlg::OnButregret() 
{
	// TODO: Add your control notification handler code here
	CDC *pDC=GetDC();
	//m_Chip = m_Chip.reset();
	//m_Chip = m_Chip->Father;




	////////////////////////////////////////////////////////////////////////////////
	//	若当前已结束游戏或栈内不足两个元素，则不进行操作
	////////////////////////////////////////////////////////////////////////////////
	if(m_stack.getLength()<2||m_iTheEnd==1)
	{
		return ;
	}
	////////////////////////////////////////////////////////////////////////////////
	////////////////////////////////////////////////////////////////////////////////





	////////////////////////////////////////////////////////////////////////////////
	////////	若当前连接不成功或对方已同意悔棋，则直接进行操作
	////////////////////////////////////////////////////////////////////////////////
	if(!m_iSuccess||m_iNet==0||m_isAgreed)
	{

		//////////////////////////////////////////////////////////////////////////////
		//	从栈中取出两个元素，并将该位置的棋子信息清空
		CPoint p = m_stack.pop();
		chess[p.x][p.y] = 0;
		p = m_stack.pop();
		chess[p.x][p.y] = 0;


		Draw(160,10,IDB_BITMAPBOARD,pDC);										//重绘棋盘，第一个参数是对话框x坐标，第二个为y坐标
		for(int i = 0;i<15;i++)
			for(int j = 0;j<15;j++)
			{																	//	重绘棋子
				if(chess[i][j]==2)
					Draw(j*33.5+160,i*33.5+10,IDB_BITMAPWHITE,pDC);
				else if(chess[i][j]==1)
					Draw(j*33.5+160,i*33.5+10,IDB_BITMAPBLACK,pDC);
			}
		//////////////////////////////////////////////////////////////////////////////
		//////////////////////////////////////////////////////////////////////////////




		///////////////////////////////////////
		//	若为对方同意悔棋，则将判定记录取反
		if(m_isAgreed)
		{
			m_isAgreed = !m_isAgreed;
			if(m_iNet == 2)
			{
				//服务器每接收到一次消息，则向除玩家外的每一个客户端发送接收到的消息
				POSITION pPos = m_listClients.GetHeadPosition();
				m_listClients.GetNext(pPos);											//	获得当前列表中的第二个客户端信息
				if(pPos)
				{
					////////////////////////////////////////////////////////////////
					//	将进行悔棋后的棋盘信息连接成字符串
					////////////////////////////////////////////////////////////////
					CString send = "-~";
					CString cs;
					for(int i=0;i<15;i++)
					{
						for(int j = 0;j<15;j++)
						{
							cs.Format("%d",chess[i][j]);
							send = send + cs;
						}
					}
					////////////////////////////////////////////////////////////////
					////////////////////////////////////////////////////////////////


					////////////////////////////////////////////////////////////////
					//	循环遍历所有客户端，并向其发送当前棋盘信息
					////////////////////////////////////////////////////////////////
					while(pPos)
					{
						CChatSocket* pCur = m_listClients.GetAt(pPos);
						//csMsgTo = "管理员~" + m_strMSG;
						pCur->Send(send, send.GetLength());
						m_listClients.GetNext(pPos);
					}
					////////////////////////////////////////////////////////////////
					////////////////////////////////////////////////////////////////

				}	//	if(pPos) END

			}	//	if(m_iNet == 2)	END

		}	//	if(m_isAgreed)	END

	}	//	if(!m_iSuccess||m_iNet==0||m_isAgreed)	END
	////////////////////////////////////////////////////////////////////////////////
	////////////////////////////////////////////////////////////////////////////////



	////////////////////////////////////////////////////////////////////////////////
	//	若当前操作对象为服务器端
	////////////////////////////////////////////////////////////////////////////////
	else if(m_iNet == 2)
	{
		POSITION pPos = m_listClients.GetHeadPosition();
			
		CChatSocket* pCur = m_listClients.GetAt(pPos);
		CString regret = "Regret~";
		pCur->Send(regret, regret.GetLength());	//	向客户端发送悔棋请求
	}
	////////////////////////////////////////////////////////////////////////////////
	////////////////////////////////////////////////////////////////////////////////


	////////////////////////////////////////////////////////////////////////////////
	//	若当前操作对象为服务器端
	////////////////////////////////////////////////////////////////////////////////
	else if(m_iNet == 1)
	{
		CString regret = "Regret~";
		m_pSocket->Send(regret, regret.GetLength());								//	向服务器端发送悔棋请求
	}
	////////////////////////////////////////////////////////////////////////////////
	////////////////////////////////////////////////////////////////////////////////

	
}
//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////




//////////////////////////////////////////////////////////////////////////////
/////////用于接收客户端玩家已经结束游戏的信息
//////////////////////////////////////////////////////////////////////////////
void CMainGameDlg::ClientClose(CChatSocket *pChatSocket)
{
	POSITION pos = m_listClients.Find(pChatSocket);
	if(pos)
	{
		if(pos==m_listClients.GetHeadPosition())							//	判断当前离开游戏的客户端是否为玩家
		{
			m_iTheEnd = 1;													//	结束游戏
			PlaySound("res\\system.wav", AfxGetInstanceHandle(), SND_FILENAME | SND_ASYNC | SND_NODEFAULT);
			MessageBox("对方已经离开游戏！","结束");
			m_iSuccess = 0;
			//m_listClients.Remove(pos);
		}
		m_listClients.RemoveAt(pos);
		pChatSocket->Close();
		delete pChatSocket;
		pChatSocket = NULL;
	}
}
/////////用于接收客户端玩家已经结束游戏的信息
//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////




//////////////////////////////////////////////////////////////////////////////
/////////客户端接受服务器端信息方法
//////////////////////////////////////////////////////////////////////////////
void CMainGameDlg::RevMsg(CClientSocket *pSocket)
{
	// 接受消息
	char *pBuf = new char[50000];
	int iBufSize = 50000;

	CDC *pDC = GetDC();
	
	int iRes = m_pSocket->Receive(pBuf, iBufSize);								//	用一个字符数组接收发送过来的消息
	if(iRes != SOCKET_ERROR)
	{
		pBuf[iRes] = NULL;
		
		UpdateData(TRUE);
		CString csMsgIN = pBuf;

		int nIndex = csMsgIN.Find("~");											//	获取标示符位置
		CString csMsgTo = csMsgIN.Left(nIndex);
		CString csMsg = csMsgIN.Mid(nIndex + 1);

		//////////////////////////////////////////////////
		//	若当前信息为连接成功信息
		//////////////////////////////////////////////////
		if(csMsgTo == "Login")
		{
			m_iSuccess = 1;														//	更改连接状态
			PlaySound("res\\system.wav", AfxGetInstanceHandle(), SND_FILENAME | SND_ASYNC | SND_NODEFAULT);
			MessageBox("连接成功","成功");										//	提示连接成功
			UpdateData(FALSE);

		}
		//////////////////////////////////////////////////
		//////////////////////////////////////////////////

		//////////////////////////////////////////////////
		//	若当前信息为悔棋请求
		//////////////////////////////////////////////////
		else if(csMsgTo == "Regret")
		{
			CPromptDlg dlg;
			dlg.m_iState = 1;
			PlaySound("res\\system.wav", AfxGetInstanceHandle(), SND_FILENAME | SND_ASYNC | SND_NODEFAULT);
			//dlg.m_csPrompt = "对方希望悔棋，是否同意？";						//	弹出提示对话框，并获取返回值
			int pos = dlg.DoModal();
			//	若同意悔棋，则直接进行操作，并则向服务器发送同意信息
			if(pos==IDOK)
			{
				CString accept = "Accept~";
				m_pSocket->Send(accept, accept.GetLength());
				m_isAgreed = true;
				OnButregret();
			}
			//	若拒绝悔棋，则向服务器发送拒绝信息
			else if(pos == IDCANCEL)
			{
				CString refuse = "Refuse~";
				m_pSocket->Send(refuse, refuse.GetLength());
			}
		}
		//////////////////////////////////////////////////
		//////////////////////////////////////////////////


		//////////////////////////////////////////////////
		//	若当前信息为新游戏请求信息
		//////////////////////////////////////////////////
		else if(csMsgTo == "Renew")
		{
			CPromptDlg dlg;
			dlg.m_iState = 2;
			PlaySound("res\\system.wav", AfxGetInstanceHandle(), SND_FILENAME | SND_ASYNC | SND_NODEFAULT);
			//dlg.m_csPrompt = "对方希望重新开始游戏，是否同意？";						//	弹出提示对话框，并获取返回值
			int pos = dlg.DoModal();
			//	若选择同意，则直接进行操作，并对客户端发送同意信息
			if(pos==IDOK)
			{
				CString accept = "AcceptRenew~";
				m_pSocket->Send(accept, accept.GetLength());
				m_isAgreed = true;
				OnButagain();
			}
			//	若选择拒绝，则向服务器发送拒绝信息
			else if(pos == IDCANCEL)
			{
				
				CString refuse = "RefuseRenew~";
				m_pSocket->Send(refuse, refuse.GetLength());
			}
		}
		//////////////////////////////////////////////////
		//////////////////////////////////////////////////


		//////////////////////////////////////////////////
		//	若为同意悔棋信息，则进行悔棋操作
		//////////////////////////////////////////////////
		else if(csMsgTo == "Accept")
		{
			m_isAgreed = true;
			OnButregret();
		}
		//////////////////////////////////////////////////
		//////////////////////////////////////////////////


		//////////////////////////////////////////////////
		//	若为同意新游戏信息，则进行新游戏操作
		//////////////////////////////////////////////////
		else if(csMsgTo == "AcceptRenew")
		{
			m_isAgreed = true;
			OnButagain();
		}
		//////////////////////////////////////////////////
		//////////////////////////////////////////////////


		//////////////////////////////////////////////////
		//	若为拒绝悔棋信息，则弹出提示框
		//////////////////////////////////////////////////
		else if(csMsgTo == "Refuse")
		{
			PlaySound("res\\system.wav", AfxGetInstanceHandle(), SND_FILENAME | SND_ASYNC | SND_NODEFAULT);
			MessageBox("对方拒绝悔棋！","提示");
		}
		//////////////////////////////////////////////////
		//////////////////////////////////////////////////


		//////////////////////////////////////////////////
		//	若为拒绝新游戏信息，则弹出提示框
		//////////////////////////////////////////////////
		else if(csMsgTo == "RefuseRenew")
		{
			PlaySound("res\\system.wav", AfxGetInstanceHandle(), SND_FILENAME | SND_ASYNC | SND_NODEFAULT);
			MessageBox("对方拒绝重新开始游戏！","提示");
		}
		//////////////////////////////////////////////////
		//////////////////////////////////////////////////


		//////////////////////////////////////////////////
		//	若发送的为当前落子坐标
		//////////////////////////////////////////////////
		else if(csMsgTo.GetAt(0)<='9'&&csMsgTo.GetAt(0)>='0')
		{
			//	解析坐标信息
			step.x=_ttoi(csMsgTo);
			step.y=_ttoi(csMsg);
			
			m_stack.push(step);													//	将落子信息入栈
			Draw(step.y*33.5+160,step.x*33.5+10,IDB_BITMAPWHITE,pDC);			//	在棋盘相应位置画出棋子
			chess[step.x][step.y] = 2;											//	更改当前棋盘位置的状态
			m_iPlayer = 1;														//	更换棋手

			////////////////////////////////////////////////////
			//	判断当前对手是否获胜
			////////////////////////////////////////////////////
			if(m_statis.isWin(chess,step.x,step.y))
			{
				//	若当前为玩家客户端，则弹出失败窗口提示
				if(m_iNet == 2)
				{
					m_iTheEnd = 1;
					CEndDlg dlg;
					dlg.m_iIsWin=0;
					dlg.DoModal();
				}
				//	若当前为观战客户端，则提示获胜方
				else if(m_iNet == 3)
				{
					PlaySound("res\\system.wav", AfxGetInstanceHandle(), SND_FILENAME | SND_ASYNC | SND_NODEFAULT);
					if(chess[step.x][step.y]==1)
						MessageBox("黑棋胜！","提示");
					else if(chess[step.x][step.y]==2)
						MessageBox("白棋胜！","提示");
				}
			}
		}
		//////////////////////////////////////////////////
		//////////////////////////////////////////////////


		//////////////////////////////////////////////////
		//	若发送的为棋盘信息
		//////////////////////////////////////////////////
		else if(csMsgTo.GetAt(0)=='-')
		{
			//	若为观战者客户端的连接成功提示，则更改状态为“观战者”
			if(csMsgTo=="--")
			{
				m_iNet = 3;
				m_iSuccess = 1;
				SetWindowText(" 五子棋--观战客户端 ");
				PlaySound("res\\system.wav", AfxGetInstanceHandle(), SND_FILENAME | SND_ASYNC | SND_NODEFAULT);
				MessageBox("连接成功","成功");
			}
			CDC *pDC=GetDC();

			//	画出棋盘，用于覆盖之前的落子信息
			Draw(160,10,IDB_BITMAPBOARD,pDC);

			
			int count = 0;				//	记录当前所解析的字符串位置


			//	逐个解析字符，更改棋盘数组状态，并画出棋子
			for(int i = 0;i<15;i++)
			{
				for(int j = 0;j<15;j++)
				{
					chess[i][j] = csMsg.GetAt(count++) - '0';
					if(chess[i][j]==2)
						Draw(j*33.5+160,i*33.5+10,IDB_BITMAPWHITE,pDC);
					else if(chess[i][j]==1)
						Draw(j*33.5+160,i*33.5+10,IDB_BITMAPBLACK,pDC);
				}
			}


		}
		//////////////////////////////////////////////////
		//////////////////////////////////////////////////


		//////////////////////////////////////////////////
		//	若接收的为聊天信息
		//////////////////////////////////////////////////
		else
		{
			UpdateData(true);										//	更新聊天框信息
			//	解析聊天信息
			CString csName = csMsgTo;
			CString msg = csMsg;
			m_csMSG = csMsgTo + "说: " + csMsg;
			int nLen=m_csALLMSG.GetLength(); // 获取内容的长度
			m_edALLMSG.SetFocus ();  // 该函数对指定的窗口设置键盘焦点。该窗口必须与调用线程的消息队列相关。
			m_edALLMSG.SetSel(nLen, nLen);  // 使文本框的滚动条自动卷到文本最后
			m_edALLMSG.ReplaceSel(m_csMSG);
			UpdateData(true);
			PlaySound("res\\msn.wav", AfxGetInstanceHandle(), SND_FILENAME | SND_ASYNC | SND_NODEFAULT);
		}
		//////////////////////////////////////////////////
		//////////////////////////////////////////////////

		delete pBuf;
		pBuf = NULL;
	}
}
/////////客户端接受服务器端信息方法
//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////








//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
/////////用于接收客户端的连接消息，并将其加入到Socket列表中
void CMainGameDlg::GetMSG()
{
	CChatSocket* pSocket = new CChatSocket(this);

	if(!m_pSrvSocket->Accept(*pSocket))
	{
		PlaySound("res\\system.wav", AfxGetInstanceHandle(), SND_FILENAME | SND_ASYNC | SND_NODEFAULT);
		MessageBox("连接客户端失败!");
	}
	else
	{
		m_listClients.AddTail(pSocket);// 不断接收新的
	}
}
/////////用于接收客户端的连接消息，并将其加入到Socket列表中
//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////




//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
////////服务器端接收客户端信息方法
void CMainGameDlg::RevMsg(CChatSocket *pChatSocket)
{
	char *pBuf = new char[50000];
	int iBufSize = 50000;
	
	CDC *pDC=GetDC();													//	获取当前设备

	int iRes = pChatSocket->Receive(pBuf, iBufSize);					//	接收信息
	if(iRes != SOCKET_ERROR)
	{
		pBuf[iRes] = NULL;
		
		UpdateData(TRUE);
		CString csMsgIN = pBuf;

		int nIndex = csMsgIN.Find("~");									//	获取标示符位置
		CString csMsgTo = csMsgIN.Left(nIndex);							//	解析接收到的信息
		CString csMsg = csMsgIN.Mid(nIndex + 1);
		
		//////////////////////////////////////////////////////////////
		//	若服务器连接成功，则向客户端发送一则连接成功提示信息
		//////////////////////////////////////////////////////////////
		if(csMsgTo == "Login")
		{
			//////////////////////////////////////////////////////////////
			//	向最后一个连接进来的客户端发送一个连接成功的消息
			//////////////////////////////////////////////////////////////
			POSITION pPos = m_listClients.GetTailPosition();
			CChatSocket* pCur = m_listClients.GetAt(pPos);

			/////////////////////////////////////////////////////////////////
			//	若当前服务器列表中只有一个对象，则服务器弹出提示连接成功窗口
			/////////////////////////////////////////////////////////////////
			if(m_listClients.GetCount()==1)
			{
				CString csLogin = "Login~";
				pCur->Send(csLogin, csLogin.GetLength());							//	向客户端发送连接成功信息
				m_iSuccess = 1;
				PlaySound("res\\system.wav", AfxGetInstanceHandle(), SND_FILENAME | SND_ASYNC | SND_NODEFAULT);
				MessageBox("连接成功","成功");

				//	更新棋盘
				m_isAgreed = true;
				OnButagain();
			}
			/////////////////////////////////////////////////////////////////
			/////////////////////////////////////////////////////////////////


			/////////////////////////////////////////////////////////////////
			//	若当前连接的为观战对象，则向其发送棋盘信息
			/////////////////////////////////////////////////////////////////
			else
			{
				//	将棋盘信息连接成一个字符串
				CString send = "--~";
				CString cs;
				AfxSocketInit();
				for(int i=0;i<15;i++)
				{
					for(int j = 0;j<15;j++)
					{
						cs.Format("%d",chess[i][j]);
						send = send + cs;
					}
				}
				pCur->Send(send, send.GetLength());
			}
			/////////////////////////////////////////////////////////////////
			/////////////////////////////////////////////////////////////////
			UpdateData(FALSE);
		}
		/////////////////////////////////////////////////////////////////
		//	若接收到的为悔棋请求
		/////////////////////////////////////////////////////////////////
		else if(csMsgTo == "Regret")
		{
			CPromptDlg dlg;
			dlg.m_iState = 1;
			//dlg.m_csPrompt = "对方希望悔棋，是否同意？";
			PlaySound("res\\system.wav", AfxGetInstanceHandle(), SND_FILENAME | SND_ASYNC | SND_NODEFAULT);
			int pos = dlg.DoModal();
			POSITION pPos = m_listClients.GetHeadPosition();
			CChatSocket* pCur = m_listClients.GetAt(pPos);

			//	若选择为同意，则直接进行操作，并向客户端发送同意信息
			if(pos==IDOK)
			{
				CString accept = "Accept~";
				pCur->Send(accept, accept.GetLength());
				m_isAgreed = true;
				OnButregret();
			}
			//	若选择为拒绝，则向客户端发送拒绝信息
			else if(pos == IDCANCEL)
			{
				
				CString refuse = "Refuse~";
				pCur->Send(refuse, refuse.GetLength());
			}
		}
		//////////////////////////////////////////////////////////////////
		//////////////////////////////////////////////////////////////////


		//////////////////////////////////////////////////////////////////
		//	若接收到的为新游戏请求
		//////////////////////////////////////////////////////////////////
		else if(csMsgTo == "Renew")
		{
			CPromptDlg dlg;
			dlg.m_iState = 2;
			//dlg.m_csPrompt = "对方希望重新开始游戏，是否同意？";
			PlaySound("res\\system.wav", AfxGetInstanceHandle(), SND_FILENAME | SND_ASYNC | SND_NODEFAULT);
			int pos = dlg.DoModal();
			POSITION pPos = m_listClients.GetHeadPosition();
			CChatSocket* pCur = m_listClients.GetAt(pPos);
			//	若选择同意，则直接进行新游戏操作，并向客户端发送同意信息
			if(pos==IDOK)
			{
				CString accept = "AcceptRenew~";
				pCur->Send(accept, accept.GetLength());
				m_isAgreed = true;
				OnButagain();
			}
			//	若选择拒绝，则向客户端发送拒绝信息
			else if(pos == IDCANCEL)
			{
				CString refuse = "RefuseRenew~";
				pCur->Send(refuse, refuse.GetLength());
			}
		}
		//////////////////////////////////////////////////////////////////
		//////////////////////////////////////////////////////////////////

		//////////////////////////////////////////////////////////////////
		//	若接收的为同意悔棋信息，则进行悔棋操作
		//////////////////////////////////////////////////////////////////
		else if(csMsgTo == "Accept")
		{
			m_isAgreed = true;
			OnButregret();
		}
		//////////////////////////////////////////////////////////////////
		//////////////////////////////////////////////////////////////////

		//////////////////////////////////////////////////////////////////
		//	若接收的为同意新游戏信息，则直接进行新游戏操作
		//////////////////////////////////////////////////////////////////
		else if(csMsgTo == "AcceptRenew")
		{
			m_isAgreed = true;
			OnButagain();
		}
		//////////////////////////////////////////////////////////////////
		//////////////////////////////////////////////////////////////////

		//////////////////////////////////////////////////////////////////
		//	若接收的为拒绝悔棋信息，则弹出提示框
		//////////////////////////////////////////////////////////////////
		else if(csMsgTo == "Refuse")
		{
			PlaySound("res\\system.wav", AfxGetInstanceHandle(), SND_FILENAME | SND_ASYNC | SND_NODEFAULT);
			MessageBox("对方拒绝悔棋！","提示");
		}
		//////////////////////////////////////////////////////////////////
		//////////////////////////////////////////////////////////////////

		//////////////////////////////////////////////////////////////////
		//	若接收的为拒绝新游戏信息，则弹出提示框
		//////////////////////////////////////////////////////////////////
		else if(csMsgTo == "RefuseRenew")
		{
			PlaySound("res\\system.wav", AfxGetInstanceHandle(), SND_FILENAME | SND_ASYNC | SND_NODEFAULT);
			MessageBox("对方拒绝重新开始游戏！","提示");
		}
		//////////////////////////////////////////////////////////////////
		//////////////////////////////////////////////////////////////////



		//////////////////////////////////////////////////////////////////
		//	若接收的为当前落子信息
		//////////////////////////////////////////////////////////////////
		else if(csMsgTo.GetAt(0)<='9'&&csMsgTo.GetAt(0)>='0')
		{
			//	解析当前落子信息，并将其入栈
			step.x=_ttoi(csMsgTo);
			step.y=_ttoi(csMsg);
			m_stack.push(step);

			//	画出棋子，并改变当前棋盘位置棋子状态
			Draw(step.y*33.5+160,step.x*33.5+10,IDB_BITMAPBLACK,pDC);
			chess[step.x][step.y] = 1;

			m_iPlayer = 2;													//	更换棋手

			//服务器每接收到一次消息，则向除玩家外的每一个客户端发送接收到的消息
			POSITION pPos = m_listClients.GetHeadPosition();
			m_listClients.GetNext(pPos);
			if(pPos)
			{
				CString send = "-~";
				CString cs;
				for(int i=0;i<15;i++)
				{
					for(int j = 0;j<15;j++)
					{
						cs.Format("%d",chess[i][j]);
						send = send + cs;
					}
				}
				/*CString x = "";
				CString cs = "";
				cs.Format("%d",step.x);
				x = x + cs;
				cs.Format("%d",step.y);
				x = x+"~"+cs;*/
				while(pPos)
				{
					CChatSocket* pCur = m_listClients.GetAt(pPos);
					//csMsgTo = "管理员~" + m_strMSG;
					pCur->Send(send, send.GetLength());
					
					m_listClients.GetNext(pPos);
				}
			}
			if(m_statis.isWin(chess,step.x,step.y))
			{
				m_iTheEnd = 1;
				CEndDlg dlg;
				dlg.m_iIsWin=0;
				dlg.DoModal();
			}
		}
		//////////////////////////////////////////////////////////////////
		//////////////////////////////////////////////////////////////////

		//////////////////////////////////////////////////////////////////
		//	若接收的为聊天信息
		//////////////////////////////////////////////////////////////////
		else
		{
			UpdateData(true);
			CString csName = csMsgTo;
			CString msg = csMsg;
			m_csMSG = csMsgTo + "说: " + csMsg;
			int nLen=m_csALLMSG.GetLength(); // 获取内容的长度
			m_edALLMSG.SetFocus ();  // 该函数对指定的窗口设置键盘焦点。该窗口必须与调用线程的消息队列相关。
			m_edALLMSG.SetSel(nLen, nLen);  // 使文本框的滚动条自动卷到文本最后
			m_edALLMSG.ReplaceSel(m_csMSG);
			UpdateData(true);
			PlaySound("res\\msn.wav", AfxGetInstanceHandle(), SND_FILENAME | SND_ASYNC | SND_NODEFAULT);//聊天消息音效
	
			POSITION pPos = m_listClients.GetHeadPosition();
			
			//m_listClients.GetNext(pPos);
			while(pPos)
			{
				CChatSocket* pCur = m_listClients.GetAt(pPos);
				if(pCur==pChatSocket)
				{
					m_listClients.GetNext(pPos);
					continue;
				}
				msg = csMsgTo + "~" + csMsg;
				//csMsgTo = "管理员~" + m_strMSG;
				pCur->Send(msg, msg.GetLength());
				m_listClients.GetNext(pPos);
			}
		}
		//////////////////////////////////////////////////////////////////
		//////////////////////////////////////////////////////////////////

		delete pBuf;
		pBuf = NULL;
	}
}
////////服务器端接收客户端信息方法
//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////






//////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////
//////用来绘制位图
void CMainGameDlg::Draw(int x, int y, UINT bitmap, CDC *pDC)
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
//////用来绘制位图
//////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////


//////////////////////////////////////////////////////////////////////////////////
//	点击发送按钮的时间响应方法
//////////////////////////////////////////////////////////////////////////////////
void CMainGameDlg::OnButtonSend() 
{
	// TODO: Add your control notification handler code here
	UpdateData(true);
	if(m_iSuccess&&m_csMSG!="")
	{
		CString cst = "你说:"+m_csMSG + "\r\n";
		//m_csMSG = "你说:"+m_csMSG + "\r\n";
		int nLen=m_csALLMSG.GetLength(); // 获取内容的长度
		m_edALLMSG.SetFocus ();  // 该函数对指定的窗口设置键盘焦点。该窗口必须与调用线程的消息队列相关。
		m_edALLMSG.SetSel(nLen, nLen);  // 使文本框的滚动条自动卷到文本最后
		m_edALLMSG.ReplaceSel(cst);
		//UpdateData(false);
		//CString msg = m_csMSG;
		//m_csMSG = "";
		//UpdateData(false);
		CString news;
		if(m_iNet==3)
			news = m_csName + "(观战者)~" + m_csMSG + "\r\n";
		else
			news = m_csName + "~" + m_csMSG + "\r\n";
		
		if(m_iNet==1||m_iNet==3)
		{
			m_pSocket->Send(news, news.GetLength());
		}
		else
		{
			POSITION pPos = m_listClients.GetHeadPosition();
			while(pPos)
			{
				CChatSocket* pCur = m_listClients.GetAt(pPos);
				CString csMsgTo = "管理员~" + m_csMSG + "\r\n";
				pCur->Send(csMsgTo, csMsgTo.GetLength());
				m_listClients.GetNext(pPos);
			}
		}
		UpdateData(true);
		m_csMSG = "";
		UpdateData(false);
		UpdateData(true);
	}
}
//////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////

HBRUSH CMainGameDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor) 
{
	HBRUSH hbr = CDialog::OnCtlColor(pDC, pWnd, nCtlColor);
     // TODO:  m_editMinute 和 m_editYear 对应于控件EditBox
/**     if( pWnd->GetSafeHwnd() == m_editMinute.GetSafeHwnd() ||
         pWnd->GetSafeHwnd() == m_editYear.GetSafeHwnd() )
     {*/
         //将背景色设为白色
         static HBRUSH   hbrEdit = ::CreateSolidBrush( RGB(217,239,248) );
         pDC->SetBkMode( TRANSPARENT );
         return hbrEdit;
  //   }
     // TODO:
     return hbr;
}

BOOL CMainGameDlg::PreTranslateMessage(MSG* pMsg) 
{
	// TODO: Add your specialized code here and/or call the base class
	if (WM_KEYFIRST <= pMsg->message && pMsg->message <= WM_KEYLAST)
	{
		//判断是否按下键盘Enter键
		if(pMsg->wParam==VK_RETURN)
		{
			//Do anything what you want to
			OnButtonSend();
			return TRUE;
		}
		//else return FALSE;
	}
	return CDialog::PreTranslateMessage(pMsg);
}

void CMainGameDlg::OnCancel() 
{
	// TODO: Add your control notification handler code here
	exit(0);
}
