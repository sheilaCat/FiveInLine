#if !defined(AFX_ENDDLG_H__B1C186D4_5450_4E35_AA6A_DA1E5B1041ED__INCLUDED_)
#define AFX_ENDDLG_H__B1C186D4_5450_4E35_AA6A_DA1E5B1041ED__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// EndDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CEndDlg dialog

class CEndDlg : public CDialog
{
// Construction
public:
	int m_iIsWin;
	void Draw(int x, int y, UINT bitmap, CDC *pDC);
	CEndDlg(CWnd* pParent = NULL);   // standard constructor
	CBitmapButton	m_bmpbtn;
// Dialog Data
	//{{AFX_DATA(CEndDlg)
	enum { IDD = IDD_END_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CEndDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CEndDlg)
	afx_msg void OnPaint();
	virtual BOOL OnInitDialog();
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ENDDLG_H__B1C186D4_5450_4E35_AA6A_DA1E5B1041ED__INCLUDED_)
