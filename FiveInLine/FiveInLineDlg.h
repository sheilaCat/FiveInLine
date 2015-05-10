// FiveInLineDlg.h : header file
//

#if !defined(AFX_FIVEINLINEDLG_H__4D58F2BD_68A5_4D9D_972F_868FF07683DF__INCLUDED_)
#define AFX_FIVEINLINEDLG_H__4D58F2BD_68A5_4D9D_972F_868FF07683DF__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CFiveInLineDlg dialog
#include "ColorStatic.h"
#include "ColorBtn.h"

class CFiveInLineDlg : public CDialog
{
// Construction
public:
	CFiveInLineDlg(CWnd* pParent = NULL);	// standard constructor
public:
	CBitmap		m_bmpBackGround;	//the back of the dialog

	//
	//与控件按钮关联的成员变量
	//
	CBitmapButton	m_bmpbtnClose;
	CBitmapButton	m_bmpbtnTwoState;
	CColorStatic	m_csStatic1;
	CColorStatic	m_csTwoState;
	CColorStatic	m_csAttribute;
	BOOL			m_bEnable;
	//为按钮添加位图
	CBitmapButton m_bmpbtnStart;

// Dialog Data
	//{{AFX_DATA(CFiveInLineDlg)
	enum { IDD = IDD_FIVEINLINE_DIALOG };
//	CButton	m_bmpbtnClose;
//	CButton	m_bmpbtnTwoState;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CFiveInLineDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	void OnLButtonDown (UINT nFlags, CPoint point);
	BOOL OnSetCursor (CWnd* pWnd, UINT nHitTest, UINT message);

	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CFiveInLineDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnTwoState();
	afx_msg void OnClose();
	afx_msg void OnStartgame();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_FIVEINLINEDLG_H__4D58F2BD_68A5_4D9D_972F_868FF07683DF__INCLUDED_)
