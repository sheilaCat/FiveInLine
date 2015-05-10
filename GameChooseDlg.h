#if !defined(AFX_GAMECHOOSEDLG_H__F1139466_51AC_4769_885A_DCF05EE1EC4F__INCLUDED_)
#define AFX_GAMECHOOSEDLG_H__F1139466_51AC_4769_885A_DCF05EE1EC4F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// GameChooseDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CGameChooseDlg dialog

class CGameChooseDlg : public CDialog
{
// Construction
public:
	CGameChooseDlg(CWnd* pParent = NULL);   // standard constructor
	CBitmapButton m_bmpbtnSingle;
	CBitmapButton m_bmpbtnDouble;
	CBitmapButton m_bmpbtnConnect;
	CBitmapButton m_bmpbtnCreate;
	CBitmapButton m_bmpbtnClose;
	CBitmap	m_bmpBackGround;
// Dialog Data
	//{{AFX_DATA(CGameChooseDlg)
	enum { IDD = IDD_GAMECHOOSE_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CGameChooseDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CGameChooseDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg void OnClosebtn();
	afx_msg void OnSingle();
	afx_msg void OnDouble();
	afx_msg void OnCreate();
	afx_msg void OnConnect();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_GAMECHOOSEDLG_H__F1139466_51AC_4769_885A_DCF05EE1EC4F__INCLUDED_)
