#if !defined(AFX_PROMPTDLG_H__7DE5E4ED_EBBD_48B5_A5EE_8B8069B2ADA4__INCLUDED_)
#define AFX_PROMPTDLG_H__7DE5E4ED_EBBD_48B5_A5EE_8B8069B2ADA4__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// PromptDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CPromptDlg dialog

class CPromptDlg : public CDialog
{
// Construction
public:
	void Draw(int x, int y, UINT bitmap, CDC *pDC);
	CPromptDlg(CWnd* pParent = NULL);   // standard constructor
	int m_iState;						//	记录当前窗体需要显示的信息
	CBitmapButton	m_bmpbtnOK;
	CBitmapButton	m_bmpbtnCancel;
	CBitmap m_bmpBackGround;
// Dialog Data
	//{{AFX_DATA(CPromptDlg)
	enum { IDD = IDD_PROMPT_DIALOG };
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPromptDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CPromptDlg)
	afx_msg void OnPaint();
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PROMPTDLG_H__7DE5E4ED_EBBD_48B5_A5EE_8B8069B2ADA4__INCLUDED_)
