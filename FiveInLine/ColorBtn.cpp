// ColorBtn.cpp: implementation of the CColorBtn class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "FiveInLine.h"
#include "ColorBtn.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CColorBtn::CColorBtn()
{

}

CColorBtn::~CColorBtn()
{

}

void CColorBtn::SetBackColor(COLORREF backColor)
{
	m_backColor = backColor;
	m_brush.CreateSolidBrush (m_backColor);
}

HBRUSH CColorBtn::CtlColor(CDC *pDC, UINT nCtlColor)
{
	pDC->SetBkMode (TRANSPARENT);
	return (HBRUSH)m_brush;
}
