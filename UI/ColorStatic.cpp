// ColorStatic.cpp: implementation of the CColorStatic class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "..\FiveInLine.h"
#include "ColorStatic.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CColorStatic::CColorStatic()
{
	m_clrText = RGB (0, 0, 0);
}

CColorStatic::~CColorStatic()
{

}

void CColorStatic::OnPaint()
{
	CPaintDC dc (this);

	CRect rect;
	GetClientRect (&rect);

	dc.SetBkMode (TRANSPARENT);

	CFont *pFont = GetParent ()->GetFont ();
	CFont *pOldFont;
	pOldFont = dc.SelectObject (pFont);

	dc.SetTextColor (m_clrText);
	CString strCaption;
	this->GetWindowText (strCaption);

	dc.DrawText (strCaption, &rect, DT_CENTER);
	dc.SelectObject (pOldFont);
}

void CColorStatic::SetTextColor(COLORREF clrText)
{
	m_clrText = clrText;
}
