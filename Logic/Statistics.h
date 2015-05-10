// Statistics.h: interface for the CStatistics class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_STATISTICS_H__62132B36_80AC_4F6A_8467_E9244330EA0F__INCLUDED_)
#define AFX_STATISTICS_H__62132B36_80AC_4F6A_8467_E9244330EA0F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CStatistics  
{
public:
	//int * getNext(int chess[15][15]);
	void Renew(int chess[15][15]);
	void Renew();
	int Min(int i,int j);														//返回两个数中的较小值
	bool isWin(int chess[15][15],int i,int j);
	int m_iUserScore[15][15];
	int m_iCpuScore[15][15];
	int getScore(int chess[15][15],int i,int j);								//获取当前位置的分数
	int m_iChess[15][15];														//创建棋盘数组，1为黑棋，2为白棋

	int Continuous(int num,int times,int color,int chess[15][15],int i,int j);	//查找当前连续num个color色棋子有times次，返回值为两端不为空的位置最小数

	//bool Continuous(int num,int times,int color,int chess[15][15],int i,int j,int direction[8]);//查找当前连续num个color色棋子有times次


	int m_iCpuSum;
	int m_iUserSum;

	//double m_iTag;//战术选择标记
	CStatistics();
	virtual ~CStatistics();

private:
	//bool next(int direction,int chess[15][15],int i,int j,int color);//判断该方向上的下一个位置是否可用
	int m_iFill;
};

#endif // !defined(AFX_STATISTICS_H__62132B36_80AC_4F6A_8467_E9244330EA0F__INCLUDED_)
