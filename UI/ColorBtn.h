// ColorBtn.h: interface for the CColorBtn class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_COLORBTN_H__45DB4ACC_DDB7_4A4C_AD3A_DF658138FB22__INCLUDED_)
#define AFX_COLORBTN_H__45DB4ACC_DDB7_4A4C_AD3A_DF658138FB22__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CColorBtn  
{
public:
	CColorBtn();
	virtual ~CColorBtn();
    void SetBackColor (COLORREF backColor);
public:
	CBrush		m_brush;
protected:
	COLORREF	m_backColor;
protected:
	HBRUSH CtlColor (CDC* pDC, UINT nCtlColor);
};

#endif // !defined(AFX_COLORBTN_H__45DB4ACC_DDB7_4A4C_AD3A_DF658138FB22__INCLUDED_)
