#if !defined(AFX_SRVSOCKET_H__7433E74C_E807_45BE_8F4A_DF2F4E8E9717__INCLUDED_)
#define AFX_SRVSOCKET_H__7433E74C_E807_45BE_8F4A_DF2F4E8E9717__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// SrvSocket.h : header file
//

//#include "MainGameDlg.h"
#include <afxsock.h>
//#pragma comment(lib, "ws2_32.lib ")

/////////////////////////////////////////////////////////////////////////////
// CSrvSocket command target

class CSrvSocket : public CSocket
{
// Attributes
public:

// Operations
public:
	CSrvSocket();
	CSrvSocket(CWnd* pWnd);
	virtual ~CSrvSocket();
	CWnd* m_pParentWnd;// 指向父对话框
	

// Overrides
public:
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSrvSocket)
	public:
	virtual void OnAccept(int nErrorCode);
	//}}AFX_VIRTUAL

	// Generated message map functions
	//{{AFX_MSG(CSrvSocket)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG

// Implementation
protected:
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SRVSOCKET_H__7433E74C_E807_45BE_8F4A_DF2F4E8E9717__INCLUDED_)
