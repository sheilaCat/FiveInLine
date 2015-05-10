// FiveInLineDlg.h : header file
//

#if !defined(AFX_FIVEINLINEDLG_H__4D58F2BD_68A5_4D9D_972F_868FF07683DF__INCLUDED_)
#define AFX_FIVEINLINEDLG_H__4D58F2BD_68A5_4D9D_972F_868FF07683DF__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CFiveInLineDlg dialog

class CFiveInLineDlg : public CDialog
{
// Construction
public:
	CFiveInLineDlg(CWnd* pParent = NULL);	// standard constructor
public:
	CBitmap	m_bmpBackGround;				//设置背景图片


	//与控件按钮关联的成员变量
	CBitmapButton	m_bmpbtnClose;			//关闭窗口按钮
	CBitmapButton	m_bmpbtnStart;			//开始游戏按钮

// Dialog Data
	//{{AFX_DATA(CFiveInLineDlg)
	enum { IDD = IDD_FIVEINLINE_DIALOG };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CFiveInLineDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CFiveInLineDlg)
	virtual BOOL OnInitDialog();					
	afx_msg void OnPaint();
	afx_msg void OnClose();
	afx_msg void OnStartgame();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_FIVEINLINEDLG_H__4D58F2BD_68A5_4D9D_972F_868FF07683DF__INCLUDED_)
