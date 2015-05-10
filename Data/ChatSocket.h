#if !defined(AFX_CHATSOCKET_H__A4778631_F2E5_4B93_B8BF_83343282971A__INCLUDED_)
#define AFX_CHATSOCKET_H__A4778631_F2E5_4B93_B8BF_83343282971A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ChatSocket.h : header file
//

#include <afxsock.h>
//#pragma comment(lib, "ws2_32.lib ")

/////////////////////////////////////////////////////////////////////////////
// CChatSocket command target

class CChatSocket : public CSocket
{
// Attributes
public:

// Operations
public:
	CChatSocket();
	CChatSocket(CWnd* pWnd);
	virtual ~CChatSocket();

// Overrides
public:
	CWnd* m_pParentWnd;											//	父类窗口组件
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CChatSocket)
	public:
	virtual void OnAccept(int nErrorCode);
	virtual void OnClose(int nErrorCode);
	virtual void OnReceive(int nErrorCode);
	//}}AFX_VIRTUAL

	// Generated message map functions
	//{{AFX_MSG(CChatSocket)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG

// Implementation
protected:
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CHATSOCKET_H__A4778631_F2E5_4B93_B8BF_83343282971A__INCLUDED_)
