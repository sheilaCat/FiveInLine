#if !defined(AFX_LOGINDLG_H__2CFD967F_4159_47E6_9350_52BA489DCA56__INCLUDED_)
#define AFX_LOGINDLG_H__2CFD967F_4159_47E6_9350_52BA489DCA56__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// LoginDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CLoginDlg dialog

class CLoginDlg : public CDialog
{
// Construction
public:
	CLoginDlg(CWnd* pParent = NULL);   // standard constructor
	CBitmap	m_bmpBackGround;
	CBitmapButton m_bmpbtnGo;
	CBitmapButton m_bmpbtnExit;

// Dialog Data
	//{{AFX_DATA(CLoginDlg)
	enum { IDD = IDD_LOGIN_DIALOG };
	CIPAddressCtrl	m_ipAddress;
	CString	m_csName;
	CString	m_csIPAddress;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CLoginDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CLoginDlg)
	virtual void OnOK();
	virtual void OnCancel();
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg void OnButexit();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_LOGINDLG_H__2CFD967F_4159_47E6_9350_52BA489DCA56__INCLUDED_)
