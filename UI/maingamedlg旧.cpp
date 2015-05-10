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
}


void CMainGameDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CMainGameDlg)
	DDX_Control(pDX, IDC_EDIT_ALLMSG, m_edALLMSG);
	DDX_Text(pDX, IDC_EDIT_ALLMSG, m_csALLMSG);
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





//////////////////////////////////////////////////////////////////////////////////
	/////////////使用另一种更便于实现的方法更换按钮位图/////////////
//////////////////////////////////////////////////////////////////////////////////

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

	m_bmpbtnSend.LoadBitmaps(IDB_BITMAPSEND1,IDB_BITMAPSEND2);
	m_bmpbtnSend.SubclassDlgItem(IDC_BUTTON_SEND,this);
	m_bmpbtnSend.SizeToContent();
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
			chess[i][j] = 0;
		}
	m_iTheEnd = 0;
	m_isAgreed = false;
	m_iPlayer = 2;
	m_iSuccess = 0;
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
		SetWindowText(" 五子棋--客户端 ");

		// 创建Socket套接字

		m_pSocket = new CClientSocket(this);

		//m_pSocket->Create(7000);

		if(!m_pSocket->Create()||!m_pSocket->Connect(m_csIPAddress, 7000))
		{
			delete m_pSocket;
			m_pSocket = NULL;
			MessageBox(" 建立连接失败！");
			return FALSE;
		}

		// 创建连接服务器
		// 向服务器端发送一个注册成功的消息
		CString csLogin = "Login~";
		m_pSocket->Send(csLogin, csLogin.GetLength());

	}
	

	//服务器端进行的操作
	else if(m_iNet==2)
	{

		m_pSrvSocket = new CSrvSocket(this);

		
		// 创建服务
		SetWindowText(" 五子棋--服务器端 ");

		if (!m_pSrvSocket->Create(7000))
		{
			delete m_pSrvSocket;
			m_pSrvSocket = NULL;
			MessageBox("绑定失败!");
			return FALSE;
		}

		// 启动监听
		m_pSrvSocket->Listen();
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
	}
}

void CMainGameDlg::OnLButtonDown(UINT nFlags, CPoint point)
{
	PostMessage (WM_NCLBUTTONDOWN, HTCAPTION, MAKELPARAM (point.x, point.y));


	if(m_iTheEnd==0)
	{
		if(point.x>172&&point.x<680&&point.y>0&&point.y<530)
		{
			//玩家落子
			PlaySound("res\\start.wav", AfxGetInstanceHandle(), SND_FILENAME | SND_ASYNC | SND_NODEFAULT);
	
			int j = (int)((point.x-183)/33.5);
			int i = (int)((point.y-18)/33.5);
			int x = (int)(j*33.5+183);
			int y = (int)(i*33.5+18);


			CDC *pDC=GetDC();//获取当前设备句柄

			//当前位置无棋子时，在当前位置画出白色棋子
			if(chess[i][j] == 0)
			{

//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
//////////////////局域网对战模块
				if(m_iSuccess==1)
				{
					if(m_iNet==2&&m_iPlayer==2)
					{
						Draw(x,y,IDB_BITMAPWHITE,pDC);
						chess[i][j] = 2;//将棋盘数组的该位置设置为白棋标记"2"
						//step.point2.x=i;
						//step.point2.y=j;
						step.x=i;
						step.y=j;
						m_stack.push(step);
						CString x;
						x.Format("%d",i);
						CString y;
						y.Format("%d",j);
						x = x+"~"+y;
						//m_pSocket->Send(x, x.GetLength());
						POSITION pPos = m_listClients.GetHeadPosition();
						
						while(pPos)
						{
							CChatSocket* pCur = m_listClients.GetAt(pPos);
							//csMsgTo = "管理员~" + m_strMSG;
							pCur->Send(x, x.GetLength());
							//m_strAllMSG += "你对 " + pCur->m_strNick + " 说: " + m_strMSG + "\r\n";
							
							if(m_statis.isWin(chess,i,j))
							{
								m_iTheEnd = 1;
						//		MessageBox("白棋赢！","结束");

								//	向客户端发送对方输了的信息
								//CChatSocket* pCur = m_listClients.GetAt(pPos);
								//CString lose = "Lose~";
								//CChatSocket* p = m_listClients.GetAt(pPos);
								//p->Send(lose, lose.GetLength());

								CEndDlg dlg;
								dlg.m_iIsWin=1;
								dlg.DoModal();
								return;
							}
							m_listClients.GetNext(pPos);

						}

						
						m_iPlayer = 1;
					}	//	if(m_iNet==2&&m_iPlayer==2)		END
					else if(m_iNet==1&&m_iPlayer==1)
					{
						Draw(x,y,IDB_BITMAPBLACK,pDC);
						chess[i][j] = 1;//将棋盘数组的该位置设置为黑棋标记"1"
						//step.point1.x=i;
						//step.point1.y=j;
						step.x=i;
						step.y=j;
						m_stack.push(step);

						if(m_iNet==1)
						{
							CString x;
							x.Format("%d",i);
							CString y;
							y.Format("%d",j);
							x = x+"~"+y;

							m_pSocket->Send(x, x.GetLength());
							
						}
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
						m_iPlayer = 2;
					}
				}//if(m_iSuccess==1)  END
//////////////////局域网对战模块
//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////


				//此段代码用于测试各点打分是否正确
				/*CString cs;
				cs.Format("%d",m_statis.getScore(chess,i,j));
				MessageBox(cs,"结束");*/



//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
//////////////////人机对战模块
				if(m_iNet==0||m_iSuccess==0)
				{
					if(m_iPlayer==2)
					{
						Draw(x,y,IDB_BITMAPWHITE,pDC);
						chess[i][j] = 2;//将棋盘数组的该位置设置为白棋标记"2"
						//step.point2.x=i;
						//step.point2.y=j;
						step.x=i;
						step.y=j;
						m_stack.push(step);
						m_iPlayer=1;


						if(m_statis.isWin(chess,i,j))
						{
							m_iTheEnd = 1;
							//	MessageBox("白棋赢！","结束");

							CEndDlg dlg;
							dlg.m_iIsWin=1;
							dlg.DoModal();
							return;
						}
					}
					

					//计算机落子
					if(m_iPlayer==1)
					{
						m_iPlayer=2;
						int max=0,score;
						int k,m;
						//循环遍历棋盘，更新每个空位置的分数
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
						x=(int)(j*33.5+183);
						y=(int)(i*33.5+18);
						step.x=i;
						step.y=j;
						m_stack.push(step);
						Draw(x,y,IDB_BITMAPBLACK,pDC);	//画出白棋
						chess[i][j] = 1;			//更新棋盘数组
						


						//此段代码用于测试各点打分是否正确
						/*cs.Format("%d",m_statis.getScore(chess,i,j));
						MessageBox(cs,"结束");*/

						//判断计算机是否胜利
						if(m_statis.isWin(chess,i,j))
						{
							m_iTheEnd = 1;
							//	MessageBox("黑棋赢！","结束");
							CEndDlg dlg;
							dlg.m_iIsWin=0;
							dlg.DoModal();
						}
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
	exit(0);
}

void CMainGameDlg::OnButagain() 
{
	// TODO: Add your control notification handler code here
	if(!m_iSuccess||m_iNet==0||m_isAgreed)
	{
		m_iPlayer = 2;
		m_statis.Renew(chess);
		m_iTheEnd=0;
		Invalidate(true);
		if(m_isAgreed)
		{
			m_isAgreed = !m_isAgreed;
			if(m_iNet==2)
			{
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
					
					while(pPos)
					{
						CChatSocket* pCur = m_listClients.GetAt(pPos);
						//csMsgTo = "管理员~" + m_strMSG;
						pCur->Send(send, send.GetLength());
						m_listClients.GetNext(pPos);
					}
				}
			}
		}
	}
	else if(m_iNet == 2)
	{
		POSITION pPos = m_listClients.GetHeadPosition();
			
		CChatSocket* pCur = m_listClients.GetAt(pPos);
		CString renew = "Renew~";
		pCur->Send(renew, renew.GetLength());
		
		//m_strAllMSG += "你对 " + pCur->m_strNick + " 说: " + m_strMSG + "\r\n";
		
	}
	else if(m_iNet == 1)
	{
		CString renew = "Renew~";
		m_pSocket->Send(renew, renew.GetLength());
	}
}

void CMainGameDlg::OnButmusic() 
{
	// TODO: Add your control notification handler code here
	
}

void CMainGameDlg::OnButregret() 
{
	// TODO: Add your control notification handler code here
	CDC *pDC=GetDC();
	//m_Chip = m_Chip.reset();
	//m_Chip = m_Chip->Father;
	if(m_stack.getLength()<2||m_iTheEnd==1)
	{
		return ;
	}


////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
///////对网络部分进行操作
	if(!m_iSuccess||m_iNet==0||m_isAgreed)
	{
		CPoint p = m_stack.pop();
		chess[p.x][p.y] = 0;
		p = m_stack.pop();
		chess[p.x][p.y] = 0;
		if(m_isAgreed)
		{
			m_isAgreed = !m_isAgreed;
			if(m_iNet == 2)
			{
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
					
					while(pPos)
					{
						CChatSocket* pCur = m_listClients.GetAt(pPos);
						//csMsgTo = "管理员~" + m_strMSG;
						pCur->Send(send, send.GetLength());
						m_listClients.GetNext(pPos);
					}
				}
			}
		}
	}
	else if(m_iNet == 2)
	{
		POSITION pPos = m_listClients.GetHeadPosition();
			
		CChatSocket* pCur = m_listClients.GetAt(pPos);
		CString regret = "Regret~";
		pCur->Send(regret, regret.GetLength());
		

		//m_strAllMSG += "你对 " + pCur->m_strNick + " 说: " + m_strMSG + "\r\n";
		
	}
	else if(m_iNet == 1)
	{
		CString regret = "Regret~";
		m_pSocket->Send(regret, regret.GetLength());
	}
///////对网络部分进行操作   
////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////END



	Draw(186,20,IDB_BITMAPBOARD,pDC);		//重绘棋盘，第一个参数是对话框x坐标，第二个为y坐标
	//Draw(0,0,IDB_BITMAPMAINBG,pDC);
	for(int i = 0;i<15;i++)
		for(int j = 0;j<15;j++)
		{
			if(chess[i][j]==2)
				Draw(j*33.5+183,i*33.5+18,IDB_BITMAPWHITE,pDC);
			else if(chess[i][j]==1)
				Draw(j*33.5+183,i*33.5+18,IDB_BITMAPBLACK,pDC);
		}
}

//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
/////////用于接收客户端玩家已经结束游戏的信息
void CMainGameDlg::ClientClose(CChatSocket *pChatSocket)
{
	POSITION pos = m_listClients.Find(pChatSocket);
	if(pos != NULL)
	{
		if(pos==m_listClients.GetHeadPosition())
		{
			m_iTheEnd = 1;

			MessageBox("对方已经离开游戏！","结束");
			m_iSuccess = 0;
			m_listClients.RemoveHead();

		}
		pChatSocket->Close();
		delete pChatSocket;
		pChatSocket = NULL;
	}
}
/////////用于接收客户端玩家已经结束游戏的信息
//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////




//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
/////////客户端接受服务器端信息方法
void CMainGameDlg::RevMsg(CClientSocket *pSocket)
{
	// 接受消息
	char *pBuf = new char[500];
	int iBufSize = 500;

	CDC *pDC = GetDC();
	
	int iRes = m_pSocket->Receive(pBuf, iBufSize);
	if(iRes != SOCKET_ERROR)
	{
		pBuf[iRes] = NULL;
		
		UpdateData(TRUE);
		CString csMsgIN = pBuf;

		int nIndex = csMsgIN.Find("~");
		CString csMsgTo = csMsgIN.Left(nIndex);
		CString csMsg = csMsgIN.Mid(nIndex + 1);
		if(csMsgTo == "Login")
		{
			m_iSuccess = 1;
			MessageBox("连接成功","成功");
			UpdateData(FALSE);

		}
		else if(csMsgTo == "Regret")
		{
			CPromptDlg dlg;
			dlg.m_csPrompt = "对方希望悔棋，是否同意？";
			int pos = dlg.DoModal();
			if(pos==IDOK)
			{
				CString accept = "Accept~";
				m_pSocket->Send(accept, accept.GetLength());
				m_isAgreed = true;
				OnButregret();
			}
			else if(pos == IDCANCEL)
			{
				CString refuse = "Refuse~";
				m_pSocket->Send(refuse, refuse.GetLength());
			}
		}
		else if(csMsgTo == "Renew")
		{
			CPromptDlg dlg;
			dlg.m_csPrompt = "对方希望重新开始游戏，是否同意？";
			int pos = dlg.DoModal();
			if(pos==IDOK)
			{
				CString accept = "AcceptRenew~";
				m_pSocket->Send(accept, accept.GetLength());
				m_isAgreed = true;
				OnButagain();
			}
			else if(pos == IDCANCEL)
			{
				
				CString refuse = "RefuseRenew~";
				m_pSocket->Send(refuse, refuse.GetLength());
			}
		}
		else if(csMsgTo == "Accept")
		{
			m_isAgreed = true;
			OnButregret();
		}
		else if(csMsgTo == "AcceptRenew")
		{
			m_isAgreed = true;
			OnButagain();
		}
		else if(csMsgTo == "Refuse")
		{
			MessageBox("对方拒绝悔棋！","提示");
		}
		else if(csMsgTo == "RefuseRenew")
		{
			MessageBox("对方拒绝重新开始游戏！","提示");
		}
		else if(csMsgTo.GetAt(0)<='9'&&csMsgTo.GetAt(0)>='0')
		{
			step.x=_ttoi(csMsgTo);
			step.y=_ttoi(csMsg);
			m_stack.push(step);
			Draw(step.y*33.5+183,step.x*33.5+18,IDB_BITMAPWHITE,pDC);
			chess[step.x][step.y] = 2;
			m_iPlayer = 1;
			if(m_statis.isWin(chess,step.x,step.y))
			{
				m_iTheEnd = 1;
				CEndDlg dlg;
				dlg.m_iIsWin=0;
				dlg.DoModal();
			}
		}
		else if(csMsgTo.GetAt(0)=='-')
		{
			if(csMsgTo=="--")
			{
				m_iNet = 3;
				m_iSuccess = 1;
				MessageBox("连接成功","成功");
			}
			CDC *pDC=GetDC();
			Draw(186,20,IDB_BITMAPBOARD,pDC);
			int count = 0;
			for(int i = 0;i<15;i++)
			{
				for(int j = 0;j<15;j++)
				{
					chess[i][j] = csMsg.GetAt(count++) - '0';
					if(chess[i][j]==2)
						Draw(j*33.5+183,i*33.5+18,IDB_BITMAPWHITE,pDC);
					else if(chess[i][j]==1)
						Draw(j*33.5+183,i*33.5+18,IDB_BITMAPBLACK,pDC);
				}
			}
		}
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
		}
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
	char *pBuf = new char[15];
	int iBufSize = 15;
	
	
	CDC *pDC=GetDC();



	int iRes = pChatSocket->Receive(pBuf, iBufSize);
	if(iRes != SOCKET_ERROR)
	{
		pBuf[iRes] = NULL;
		
		UpdateData(TRUE);
		CString csMsgIN = pBuf;

		int nIndex = csMsgIN.Find("~");
		CString csMsgTo = csMsgIN.Left(nIndex);
		CString csMsg = csMsgIN.Mid(nIndex + 1);
		
		//若服务器连接成功，则向客户端发送一则连接成功提示信息
		if(csMsgTo == "Login")
		{

			//向最后一个连接进来的客户端发送一个连接成功的消息
			POSITION pPos = m_listClients.GetTailPosition();
			CChatSocket* pCur = m_listClients.GetAt(pPos);
			if(m_listClients.GetCount()==1)
			{
				CString csLogin = "Login~";
				pCur->Send(csLogin, csLogin.GetLength());
				m_iSuccess = 1;
				MessageBox("连接成功","成功");
				m_isAgreed = true;
				OnButagain();
			}
			else
			{
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
			UpdateData(FALSE);
		}
		else if(csMsgTo == "Regret")
		{
			CPromptDlg dlg;
			dlg.m_csPrompt = "对方希望悔棋，是否同意？";
			int pos = dlg.DoModal();
			POSITION pPos = m_listClients.GetHeadPosition();
			CChatSocket* pCur = m_listClients.GetAt(pPos);
			if(pos==IDOK)
			{
				CString accept = "Accept~";
				pCur->Send(accept, accept.GetLength());
				m_isAgreed = true;
				OnButregret();
			}
			else if(pos == IDCANCEL)
			{
				
				CString refuse = "Refuse~";
				pCur->Send(refuse, refuse.GetLength());
			}
		}
		else if(csMsgTo == "Renew")
		{
			CPromptDlg dlg;
			dlg.m_csPrompt = "对方希望重新开始游戏，是否同意？";
			int pos = dlg.DoModal();
			POSITION pPos = m_listClients.GetHeadPosition();
			CChatSocket* pCur = m_listClients.GetAt(pPos);
			if(pos==IDOK)
			{
				CString accept = "AcceptRenew~";
				pCur->Send(accept, accept.GetLength());
				m_isAgreed = true;
				OnButagain();
			}
			else if(pos == IDCANCEL)
			{
				
				CString refuse = "RefuseRenew~";
				pCur->Send(refuse, refuse.GetLength());
			}
		}
		else if(csMsgTo == "Accept")
		{
			m_isAgreed = true;
			OnButregret();
		}
		else if(csMsgTo == "AcceptRenew")
		{
			m_isAgreed = true;
			OnButagain();
		}
		else if(csMsgTo == "Refuse")
		{
			MessageBox("对方拒绝悔棋！","提示");
		}
		else if(csMsgTo == "RefuseRenew")
		{
			MessageBox("对方拒绝重新开始游戏！","提示");
		}
		else if(csMsgTo.GetAt(0)<='9'&&csMsgTo.GetAt(0)>='0')
		{
			step.x=_ttoi(csMsgTo);
			step.y=_ttoi(csMsg);
			m_stack.push(step);
			Draw(step.y*33.5+183,step.x*33.5+18,IDB_BITMAPBLACK,pDC);
			chess[step.x][step.y] = 1;
			m_iPlayer = 2;

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

			POSITION pPos = m_listClients.GetHeadPosition();
			m_listClients.GetNext(pPos);
			while(pPos)
			{
				CChatSocket* pCur = m_listClients.GetAt(pPos);
				msg = csMsgTo + "~" + csMsg;
				//csMsgTo = "管理员~" + m_strMSG;
				pCur->Send(msg, msg.GetLength());
				m_listClients.GetNext(pPos);
			}
		}
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


void CMainGameDlg::OnButtonSend() 
{
	// TODO: Add your control notification handler code here
	if(m_iSuccess)
	{
		UpdateData(true);
		CString cst = "你说:"+m_csMSG + "\r\n";
		int nLen=m_csALLMSG.GetLength(); // 获取内容的长度
		m_edALLMSG.SetFocus();  // 该函数对指定的窗口设置键盘焦点。该窗口必须与调用线程的消息队列相关。
		m_edALLMSG.SetSel(nLen, nLen);  // 使文本框的滚动条自动卷到文本最后
		m_edALLMSG.ReplaceSel(cst);
		//CString msg = m_csMSG;
		//m_csMSG = "";
		//UpdateData(false);
		CString news = m_csName + "~" + m_csMSG + "\r\n";
		
		if(m_iNet==1)
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
	}
}

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
