#if !defined(AFX_MAINGAMEDLG_H__8BF46AE4_B10C_4E2C_96F4_42F1F39D5387__INCLUDED_)
#define AFX_MAINGAMEDLG_H__8BF46AE4_B10C_4E2C_96F4_42F1F39D5387__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// MainGameDlg.h : header file
//
#include "ColorStatic.h"
#include "ColorBtn.h"
#include "..\Logic\Statistics.h"
#include "..\Data\Stack.h"
#include "..\Data\ClientSocket.h"
#include "..\Data\ChatSocket.h"
#include "..\Data\SrvSocket.h"
#include <afxtempl.h>
#include <afxsock.h>
/////////////////////////////////////////////////////////////////////////////
// CMainGameDlg dialog

class CMainGameDlg : public CDialog
{
// Construction
public:

////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////
////界面
	CMainGameDlg(CWnd* pParent = NULL);   // standard constructor
	CBitmap	m_bmpBackGround;
	CBitmapButton m_bmpbtnMusic;
	CBitmapButton m_bmpbtnAgain;
	CBitmapButton m_bmpbtnRegret;
	CBitmapButton m_bmpbtnExit;
	CBitmapButton m_bmpbtnSend;
	CBitmapButton m_bmpbtnExitReal;

	CColorStatic	m_csAttribute;
////界面
////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////


////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////
////功能

	CString m_csName;										//	客户端昵称
	bool m_isAgreed;										//	是否同意悔棋或重新开始游戏
	bool m_isSingle;										//	是否为单人游戏

	
	
	void RevMsg(CChatSocket *pChatSocket);					//	服务器端接收客户端信息的方法
	void RevMsg(CClientSocket *pChatSocket);				//	客户端接收服务器端信息的方法
	void GetMSG();											//	用于接收新的客户端
	int m_iSuccess;											//	是否连接成功					
	int	m_iMusic;											//  表示音乐状态
	//void RevMsg(CSrvSocket *pChatSocket);

	CList<CChatSocket*, CChatSocket*> m_listClients;		//	保存服务器端Socket的列表

	void ClientClose(CChatSocket *pChatSocket);				//	获得客户端关闭的消息
	CSrvSocket* m_pSrvSocket;								//	服务器端CSrvSocket类，用于监听客户端
	CChatSocket* m_Send;									//	服务器端Socket类，用于发送信息
	CClientSocket* m_pSocket;								//	客户端Socket类
	
	CString m_csIPAddress;									//	客户端需要连接的服务器所在IP地址
	int chess[15][15];										//	创建棋盘数组，1为黑棋，2为白棋
	int m_iPlayer;											//	棋手标记，1为黑棋玩家，2为白棋玩家
	int m_iNet;												//	网络连接标示符，1表示为客户端，2表示为服务器端
	void Draw(int x,int y,UINT bitmap,CDC *pDC);			//	绘图方法
	CStatistics m_statis;									//	封装着五子棋人机对战所要用到的算法
	//int chess[15][15];//创建棋盘，1为黑棋，2为白棋

	CStack m_stack;											//	保存每一步落子的栈结构
	//Node step;
	CPoint step;											//	保存当前落子的位置

	int m_iTheEnd;											//	是否游戏结束

////功能
////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////



// Dialog Data
	//{{AFX_DATA(CMainGameDlg)
	enum { IDD = IDD_MAINGAME_DIALOG };
	CRichEditCtrl	m_edALLMSG;
	CString	m_csALLMSG;
	CString	m_csMSG;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMainGameDlg)
	public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//void OnLButtonDown (UINT nFlags, CPoint point);
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CMainGameDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg void OnButexit();
	afx_msg void OnButagain();
	afx_msg void OnButmusic();
	afx_msg void OnButregret();
	afx_msg void OnButtonSend();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	afx_msg void OnCancel();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MAINGAMEDLG_H__8BF46AE4_B10C_4E2C_96F4_42F1F39D5387__INCLUDED_)
