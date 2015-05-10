// ColorStatic.h: interface for the CColorStatic class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_COLORSTATIC_H__BC867F7D_3A13_402C_B52B_D5897589DBDC__INCLUDED_)
#define AFX_COLORSTATIC_H__BC867F7D_3A13_402C_B52B_D5897589DBDC__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CColorStatic  : public CStatic
{
public:
	void SetTextColor (COLORREF clrText);
	CColorStatic();
	virtual ~CColorStatic();
COLORREF	m_clrText;	//ÎÄ±¾ÑÕÉ«
protected:
	void OnPaint();
};

#endif // !defined(AFX_COLORSTATIC_H__BC867F7D_3A13_402C_B52B_D5897589DBDC__INCLUDED_)
