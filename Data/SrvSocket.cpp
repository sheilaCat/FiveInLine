// SrvSocket.cpp : implementation file
//

#include "stdafx.h"
#include "..\FiveInLine.h"
#include "SrvSocket.h"
#include "..\UI\MainGameDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSrvSocket

CSrvSocket::CSrvSocket()
{
}

CSrvSocket::CSrvSocket(CWnd *pWnd)
{
	m_pParentWnd = pWnd;
}

CSrvSocket::~CSrvSocket()
{
}


// Do not edit the following lines, which are needed by ClassWizard.
#if 0
BEGIN_MESSAGE_MAP(CSrvSocket, CSocket)
	//{{AFX_MSG_MAP(CSrvSocket)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()
#endif	// 0

/////////////////////////////////////////////////////////////////////////////
// CSrvSocket member functions

void CSrvSocket::OnAccept(int nErrorCode) 
{
	// TODO: Add your specialized code here and/or call the base class
	((CMainGameDlg*)m_pParentWnd)->GetMSG();
	CSocket::OnAccept(nErrorCode);
}
