#if !defined(AFX_MAINGAMEDLG_H__8BF46AE4_B10C_4E2C_96F4_42F1F39D5387__INCLUDED_)
#define AFX_MAINGAMEDLG_H__8BF46AE4_B10C_4E2C_96F4_42F1F39D5387__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// MainGameDlg.h : header file
//
#include "ColorStatic.h"
#include "ColorBtn.h"
/////////////////////////////////////////////////////////////////////////////
// CMainGameDlg dialog

class CMainGameDlg : public CDialog
{
// Construction
public:
	CMainGameDlg(CWnd* pParent = NULL);   // standard constructor
	CBitmap	m_bmpBackGround;
	CBitmapButton m_bmpbtnMusic;
	CBitmapButton m_bmpbtnAgain;
	CBitmapButton m_bmpbtnRegret;
	CBitmapButton m_bmpbtnExit;

	CColorStatic	m_csAttribute;
// Dialog Data
	//{{AFX_DATA(CMainGameDlg)
	enum { IDD = IDD_MAINGAME_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMainGameDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	void OnLButtonDown (UINT nFlags, CPoint point);
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CMainGameDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MAINGAMEDLG_H__8BF46AE4_B10C_4E2C_96F4_42F1F39D5387__INCLUDED_)
