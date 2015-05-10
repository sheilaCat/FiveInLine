// ChatSocket.cpp : implementation file
//

#include "stdafx.h"
#include "..\FiveInLine.h"
#include "ChatSocket.h"
#include "..\UI\MainGameDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CChatSocket

CChatSocket::CChatSocket()
{
}

CChatSocket::CChatSocket(CWnd* pWnd)
{
	m_pParentWnd = pWnd;
}

CChatSocket::~CChatSocket()
{
}


// Do not edit the following lines, which are needed by ClassWizard.
#if 0
BEGIN_MESSAGE_MAP(CChatSocket, CSocket)
	//{{AFX_MSG_MAP(CChatSocket)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()
#endif	// 0

/////////////////////////////////////////////////////////////////////////////
// CChatSocket member functions

void CChatSocket::OnAccept(int nErrorCode) 
{
	// TODO: Add your specialized code here and/or call the base class
	((CMainGameDlg*)m_pParentWnd)->RevMsg(this);
	CSocket::OnAccept(nErrorCode);
}

void CChatSocket::OnClose(int nErrorCode) 
{
	// TODO: Add your specialized code here and/or call the base class
	((CMainGameDlg*)m_pParentWnd)->ClientClose(this);
	CSocket::OnClose(nErrorCode);
}

void CChatSocket::OnReceive(int nErrorCode) 
{
	// TODO: Add your specialized code here and/or call the base class
	((CMainGameDlg*)m_pParentWnd)->RevMsg(this);
	CSocket::OnReceive(nErrorCode);
}
