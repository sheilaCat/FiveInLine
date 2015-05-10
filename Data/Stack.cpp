// Stack.cpp: implementation of the CStack class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "..\FiveInLine.h"
#include "Stack.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CStack::CStack()
{
	top = -1;
}

CStack::~CStack()
{

}

//	弹出栈顶元素
CPoint CStack::pop()
{
	return Sta[top--];
}

//	返回栈是否为空
bool CStack::isEmpty()
{
	if(top <= -1)
		return true;
	else
		return false;
}

//	将元素入栈
void CStack::push(CPoint newPoint)
{
	Sta[++top] = newPoint;
}

//	获得栈的长度
int CStack::getLength()
{
	return top+1;
}

//	清空栈
void CStack::clear()
{
	top=-1;
}
