#if !defined(AFX_CLIENTSOCKET_H__8F406D08_948A_462F_8773_4623E7BC4FE5__INCLUDED_)
#define AFX_CLIENTSOCKET_H__8F406D08_948A_462F_8773_4623E7BC4FE5__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ClientSocket.h : header file
//


#include <afxsock.h>
//#pragma comment(lib, "ws2_32.lib ")

/////////////////////////////////////////////////////////////////////////////
// CClientSocket command target

class CClientSocket : public CSocket
{
// Attributes
public:

// Operations
public:
	CClientSocket();
	CClientSocket(CWnd* pWnd);
	virtual ~CClientSocket();
	CWnd* m_pParentWnd;			// 用于保存一个通用窗口指针

// Overrides
public:
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CClientSocket)
	public:
	virtual void OnReceive(int nErrorCode);
	//}}AFX_VIRTUAL

	// Generated message map functions
	//{{AFX_MSG(CClientSocket)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG

// Implementation
protected:
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CLIENTSOCKET_H__8F406D08_948A_462F_8773_4623E7BC4FE5__INCLUDED_)
