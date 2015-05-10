// Stack.h: interface for the CStack class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_STACK_H__CD3D7683_1A20_4E0F_894C_0271D881E80A__INCLUDED_)
#define AFX_STACK_H__CD3D7683_1A20_4E0F_894C_0271D881E80A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CStack  
{
public:
	void clear();
	int getLength();
	//void push(Node newNode);
	void push(CPoint newPoint);
	bool isEmpty();

	//Node Sta[300];
	//Node pop();
	CPoint Sta[300];
	CPoint pop();
	CStack();
	virtual ~CStack();

private:
		int top;

};

#endif // !defined(AFX_STACK_H__CD3D7683_1A20_4E0F_894C_0271D881E80A__INCLUDED_)
