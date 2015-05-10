// Statistics.cpp: implementation of the CStatistics class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "..\FiveInLine.h"
#include "Statistics.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CStatistics::CStatistics()
{
	Renew();
}

CStatistics::~CStatistics()
{

}




int CStatistics::Continuous(int num,int times,int color,int chess[15][15],int i,int j)
{
	int count=1,t=0,k = i,m = j,death=0;//非活棋数
	int dir=0;//四个方向
	bool isLive=false;

	//纵方向

	k--;
	/*if(k>=0&&chess[k][m]!=color&&chess[k][m]!=0)
	{
		if(i==14)
			death=2;
		else
			death=1;
		dir=1;
	}*/
	//while(k>=0&&chess[k][m]==color)
	while(k>=0)
	{
		if(k==0||chess[k][m]!=color)
		{
			if(k==0||chess[k][m]!=0)
			{
				if(i==14)
					death = 2;
				else
					death=1;
				dir=1;
			}
			break;
		}
		count++;
		/*if(k==0||chess[k-1][m]!=0)
		{
			if(i==14)
				death = 2;
			else
				death=1;
			dir=1;
		}
		/*if(count==num)
		{
			t++;
			if(k==0||chess[k-1][m]!=0)
			{
				if(i==14)
					death = 2;
				else
					death=1;
				dir=1;
			}
			break;
		}*/
		k--;
	}
	
	
	k=i+1;


	/*if(k<=14&&chess[k][m]!=color&&chess[k][m]!=0)
	{
		if(dir==1||i==0)
			death=2;
		else
		{
			death=1;
		}
		dir=1;
	}*/
	//while(k<=14&&chess[k][m]==color)
	while(k<=14)
	{
		if(k==14||chess[k][m]!=color)
		{
			if(k==14||chess[k][m]!=0)
			{
				if(dir==1||i==0)
					death=2;
				else
				{
					death=1;
				}
				dir=1;
			}
			else if(dir!=1&&count==num)
			{
				isLive=true;
			}
			break;
		}
		count++;
		/*if(k==14||chess[k+1][m]!=0)
		{
			if(dir==1||i==0)
				death=2;
			else
			{
				death=1;
			}
			dir=1;
		}*/
		k++;
	}
	if(count==num)
	{
		t++;
		if(dir!=1)
		{
			isLive=true;
		}
	}
	
	
	k=i;
	count=1;

	//横方向


	m=j-1;
	
	/*if(m>=0&&chess[k][m]!=color&&chess[k][m]!=0)
	{
		if(j==14)
			death=2;
		else
			death=1;
		dir=2;
	}
	while(m>=0&&chess[k][m]==color)*/
	while(m>=0)
	{
		if(m==0||chess[k][m]!=color)
		{
			if(m==0||chess[k][m]!=0)
			{
				if(j==14)
					death=2;
				else
					death=1;
				dir=2;
			}
			break;
		}
		count++;
		/*if(m==0||chess[k][m-1]!=0)
		{
			if(j==14)
				death=2;
			else
				death=1;
			dir=2;
		}
		/*if(count==num)
		{
			t++;
			if(m==0||chess[k][m-1]!=0)
			{
				if(j==14)
					death=2;
				else
					death=1;
				dir=2;
			}
			break;
		}*/
		m--;
	}

	m=j+1;



	/*if(m<=14&&chess[k][m]!=color&&chess[k][m]!=0)
	{
		if(dir==2||j==0)
			death=2;
		else
		{
			death=1;
		}
		dir=2;
	}
	while(m<=14&&chess[k][m]==color)*/
	while(m<=14)
	{
		if(m==14||chess[k][m]!=color)
		{
			if(m==14||chess[k][m]!=0)
			{
				if(dir==2||j==0)
					death=2;
				else
					death=1;
				dir=2;
			}
			else if(dir!=2&&count==num)
			{
				isLive=true;
			}
			break;
		}
		count++;
		/*if(m==14||chess[k][m+1]!=0)
		{
			if(dir==2||j==0)
				death=2;
			else
				death=1;
			dir=2;
		}
		/*if(count==num)
		{
			t++;
			if(m==14||chess[k][m+1]!=0)
			{
				if(dir==2||j==0)
					death=2;
				else
					death=1;
				dir=2;
			}
			else if(dir!=2)
			{
				isLive=true;
			}
			break;
		}*/
		m++;
	}
	if(count==num)
	{
		t++;
		if(dir!=2)
		{
			isLive=true;
		}
	}

	count=1;

	//左上右下


	m=j-1;
	k=i-1;

	/*if(m>=0&&k>=0&&chess[k][m]!=color&&chess[k][m]!=0)
	{
		if(i==14||j==14)
			death=2;
		else
			death=1;
		dir=3;
	}
	while(k>=0&&m>=0&&chess[k][m]==color)*/
	while(k>=0&&m>=0)
	{
		if(k==0||m==0||chess[k][m]!=color)
		{
			if(k==0||m==0||chess[k][m]!=0)
			{
				if(i==14||j==14)
					death=2;
				else
					death=1;
				dir = 3;
			}
			break;
		}
		count++;
		/*if(k==0||m==0||chess[k-1][m-1]!=0)
		{
			if(i==14||j==14)
				death=2;
			else
				death=1;
			dir = 3;
		}
		/*if(count==num)
		{
			t++;
			if(k==0||m==0||chess[k-1][m-1]!=0)
			{
				if(i==14||j==14)
					death=2;
				else
					death=1;
				dir = 3;
			}
			break;
		}*/
		m--;
		k--;
	}
	k=i+1;
	m=j+1;

	/*if(k<=14&&m<=14&&chess[k][m]!=color&&chess[k][m]!=0)
	{
		if(dir==3||i==0||j==0)
			death=2;
		else
		{
			death=1;
		}
		dir=3;
	}
	while(m<=14&&k<=14&&chess[k][m]==color)*/
	while(m<=14&&k<=14)
	{
		if(k==14||m==14||chess[k][m]!=color)
		{
			if(k==14||m==14||chess[k][m]!=0)
			{
				if(dir==3||i==0||j==0)
					death=2;
				else
				{
					death=1;
				}
				dir = 3;
			}
			else if(dir!=3&&count==num)
			{
				isLive=true;
			}
			break;
		}
		count++;
		/*if(k==14||m==14||chess[k+1][m+1]!=0)
		{
			if(dir==3||i==0||j==0)
				death=2;
			else
			{
				death=1;
			}
			dir = 3;
		}
		/*if(count==num)
		{
			t++;
			if(k==14||m==14||chess[k+1][m+1]!=0)
			{
				if(dir==3||i==0||j==0)
					death=2;
				else
				{
					death=1;
				}
				dir = 3;
			}
			else if(dir!=3)
			{
				isLive=true;
			}
			break;
		}*/
		m++;
		k++;
	}
	if(count==num)
	{
		t++;
		if(dir!=3)
		{
			isLive=true;
		}
	}

	count=1;
	

	//左下右上


	k=i+1;
	m=j-1;
	/*if(k<=14&&m>=0&&chess[k][m]!=color&&chess[k][m]!=0)
	{
		if(i==0||j==14)
			death=2;
		else
			death=1;
		dir=4;
	}
	while(k<=14&&m>=0&&chess[k][m]==color)*/
	while(k<=14&&m>=0)
	{
		if(k==14||m==0||chess[k][m]!=color)
		{
			if(k==14||m==0||chess[k][m]!=0)
			{
				if(i==0||j==14)
					death=2;
				else
					death=1;
				dir=4;
			}
			break;
		}
		count++;
		/*if(k==14||m==0||chess[k+1][m-1]!=0)
		{
			if(i==0||j==14)
				death=2;
			else
				death=1;
			dir=4;
		}
		/*if(count==num)
		{
			t++;
			if(k==14||m==0||chess[k+1][m-1]!=0)
			{
				if(i==0||j==14)
					death=2;
				else
					death=1;
				dir=4;
			}
			break;
		}*/
		m--;
		k++;
	}
	k=i-1;
	m=j+1;

	/*if(k>=0&&m<=14&&chess[k][m]!=color&&chess[k][m]!=0)
	{
		if(dir==4||i==14||j==0)
			death=2;
		else
		{
			death=1;
		}
		dir=4;
	}
	while(k>=0&&m<=14&&chess[k][m]==color)*/
	while(k>=0&&m<=14)
	{
		if(k==0||m==14||chess[k][m]!=color)
		{
			if(k==0||m==14||chess[k][m]!=0)
			{
				if(dir==4||i==14||j==0)
					death=2;
				else
				{
					death=1;
				}
				dir=4;
			}
			else if(dir!=4&&count==num)
			{
				isLive=true;
			}
			break;
		}
		count++;
		/*if(k==0||m==14||chess[k-1][m+1]!=0)
		{
			if(dir==4||i==14||j==0)
				death=2;
			else
			{
				death=1;
			}
			dir=4;
		}
		/*if(count==num)
		{
			t++;
			if(k==0||m==14||chess[k-1][m+1]!=0)
			{
				if(dir==4||i==14||j==0)
					death=2;
				else
				{
					death=1;
				}
				dir=4;
			}
			else if(dir!=4)
			{
				isLive=true;
			}
			break;
		}*/
		m++;
		k--;
	}
	if(count==num)
	{
		t++;
		if(dir!=4)
		{
			isLive=true;
		}
	}
	//if(count==num)t++;
	if(t==times&&isLive)return 0;
	else if(t==times)
		return death;
	else return -1;
}

int CStatistics::getScore(int chess[][15], int i, int j)
{
	int score=0,death;
	if(Continuous(5,1,1,chess,i,j)!=-1)
		score=10800;
	else if(Continuous(5,1,2,chess,i,j)!=-1)
		score=-10500;
	else if(Continuous(4,1,1,chess,i,j)!=-1)
	{
		death=Continuous(4,1,1,chess,i,j);
		if(death==2)
			score = 0;
		else if(death == 1)
			score = 5000;
		else
			score=10000;
	}
	else if(Continuous(4,2,2,chess,i,j)!=-1)
	{
		death=Continuous(4,2,2,chess,i,j);
		if(death==2)
			score = 0;
		else if(death == 1)
			score = 4000;
		else
			score=9000;
	}
	else if(Continuous(4,1,2,chess,i,j)!=-1)
	{
		death=Continuous(4,1,2,chess,i,j);
		if(Continuous(3,1,1,chess,i,j)!=-1||Continuous(3,1,2,chess,i,j)!=-1)
		{
			int death1=Continuous(3,1,1,chess,i,j);
			int death2=Continuous(3,1,2,chess,i,j);
			if(death1==-1)
			{
				death1=death2;
			}
			else if(death1 > death2)
			{
				death1 = death2;
			}

			if(death==2&&death1==2)
			{
				score = 0;
			}
			else if(death==2&&death1==1)
			{
				score = 1000;
			}
			else if(death==2&&death1==0)
			{
				if(Continuous(3,1,1,chess,i,j)==0)
					score = 7000;
				else
					score = 6000;
			}
			else if(death==1&&death1==2)
			{
				score = 4000;
			}
			else if(death==1&&death1==1)
			{
				score = 4300;
			}
			else if(death==1&&death1==0)
			{
				score = 4500;
			}
			else if(death==0&&death1==2)
			{
				score = 8000;
			}
			else if(death==0&&death1==1)
			{
				score = 8100;
			}
			else if(death==0&&death1==0)
				score=8500;
		}
		else
		{
			if(death == 2)
				score = 0;
			else if(death == 1)
				score = 4000;
			else
				score=8000;
		}
	}
	else if(Continuous(3,1,2,chess,i,j)!=-1&&Continuous(3,1,1,chess,i,j)!=-1)
	{
		death = Continuous(3,1,2,chess,i,j);
		int death1 = Continuous(3,1,1,chess,i,j);
		if(death == 2&&death1==2)
			score = 0;
		else if(death == 2&&death1==1)
			score = 2000;
		else if(death == 2&&death1==0)
			score=7000;
		else if(death == 1&&death1==2)
			score=1000;
		else if(death == 1&&death1==1)
			score=2500;
		else if(death == 1&&death1==0)
			score=7300;
		else if(death == 0&&death1==2)
			score=6000;
		else if(death == 0&&death1==1)
			score=7300;
		else
			score=7500;
	}

	else if(Continuous(3,2,1,chess,i,j)!=-1)
	{
		death = Continuous(3,2,1,chess,i,j);
		if(death == 2)
			score = 0;
		else if(death == 1)
			score = 1200;
		else
			score=7700;
	}

	else if(Continuous(3,2,2,chess,i,j)!=-1)
	{
		death = Continuous(3,2,2,chess,i,j);
		if(death == 2)
			score = 0;
		else if(death == 1)
			score = 1000;
		else
			score=7500;
	}
	
	else if(Continuous(3,1,1,chess,i,j)!=-1)
	{
		death = Continuous(3,1,1,chess,i,j);
		if(death == 2)
			score = 0;
		else if(death == 1)
			score = 2000;
		else
			score=7000;
	}

	else if(Continuous(3,1,2,chess,i,j)!=-1)
	{
		death = Continuous(3,1,2,chess,i,j);
		if(death == 2)
			score = 0;
		else if(death == 1)
			score = 1000;
		else
			score=6000;
	}
	
	
	else if(Continuous(2,2,1,chess,i,j)!=-1)
	{
		death = Continuous(2,2,1,chess,i,j);
		if(death == 0)
			score=3500;
		else
			score = 0;
	}
	
	else if(Continuous(2,1,1,chess,i,j)!=-1)
	{
		death = Continuous(2,1,1,chess,i,j);
		if(death == 0)
			score = 3000;
		else
			score=0;
	}
	else if(Continuous(2,1,2,chess,i,j)!=-1)
	{
		score=3;
	}
	else if(Continuous(1,1,1,chess,i,j)!=-1)
		score=2;
	else if(Continuous(1,2,1,chess,i,j)!=-1)
		score=1;
	else
		score = 0;

	return score;
}


/*bool CStatistics::next(int direction,int chess[][15], int i, int j, int color)
{
	if(direction==1)
	{
		if(j<14&&chess[i][j+1]!=color)return false;
		else return true;
	}
	else if(direction==2)
	{
		if(j<14&&i<14&&chess[i+1][j+1]!=color)return false;
		else return true;
	}
	else if(direction==3)
	{
		if(i<14&&chess[i+1][j]!=color)return false;
		else return true;
	}
	else if(direction==4)
	{
		if(i<14&&j>0&&chess[i+1][j-1]!=color)return false;
		else return true;
	}
	else if(direction==5)
	{
		if(j>0&&chess[i][j-1]!=color)return false;
		else return true;
	}
	else if(direction==6)
	{
		if(j>0&&i>0&&chess[i-1][j-1]!=color)return false;
		else return true;
	}
	else if(direction==7)
	{
		if(i>0&&chess[i-1][j]!=color)return false;
		else return true;
	}
	else if(direction==8)
	{
		if(j<14&&i>0&&chess[i-1][j+1]!=color)return false;
		else return true;
	}
	return false;
}*/

bool CStatistics::isWin(int chess[][15], int i, int j)
{
	//判断横方向棋子个数是否为5
	int count=1;
	int k = i,m = j - 1;
	while(m>=0&&chess[k][m]==chess[i][j])
	{
		count++;
		m--;
	}
	m=j+1;
	while(m<=14&&chess[k][m]==chess[i][j])
	{
		count++;
		m++;
	}
	if(count >= 5)return true;

	m=j;

	count=1;
	//判断纵方向
	k=i-1;
	while(k>=0&&chess[k][m]==chess[i][j])
	{
		count++;
		k--;
	}
	k=i+1;
	while(k<=14&&chess[k][m]==chess[i][j])
	{
		count++;
		k++;
	}
	if(count >= 5)return true;

	count = 1;

	//判断左下右上方向
	k=i+1;
	m=j-1;
	while(k<=14&&m>=0&&chess[k][m]==chess[i][j])
	{
		count++;
		k++;
		m--;
	}
	k=i-1;
	m=j+1;
	while(k>=0&&m<=14&&chess[k][m]==chess[i][j])
	{
		count++;
		k--;
		m++;
	}
	if(count>=5)return true;

	count=1;

	//判断左上右下方向
	k=i-1;
	m=j-1;
	while(k>=0&&m>=0&&chess[k][m]==chess[i][j])
	{
		count++;
		k--;
		m--;
	}
	k=i+1;
	m=j+1;
	while(k<=14&&m<=14&&chess[k][m]==chess[i][j])
	{
		count++;
		k++;
		m++;
	}
	if(count>=5)return true;

	return false;
}

int CStatistics::Min(int i, int j)
{
	if(i<j)return i;
	else return j;
}

void CStatistics::Renew()
{
	m_iUserSum = 0;
	m_iCpuSum = 0;
	for(int i = 0;i < 15;i++)
		for(int j = 0;j < 15;j++)
		{
			m_iChess[i][j]=0;
			if(i<=7&&j<=7)
			{
				m_iCpuScore[i][j]=Min(i,j);
				m_iUserScore[i][j]=Min(i,j);
			}
			else if(i<=7)
			{
				m_iCpuScore[i][j]=Min(i,14-j);
				m_iUserScore[i][j]=Min(i,14-j);
			}
			else if(j<=7)
			{
				m_iCpuScore[i][j]=Min(14-i,j);
				m_iUserScore[i][j]=Min(14-i,j);
			}
			else
			{
				m_iCpuScore[i][j]=Min(14-i,14-j);
				m_iUserScore[i][j]=Min(14-i,14-j);
			}
		}
}

void CStatistics::Renew(int chess[][15])
{
	m_iUserSum = 0;
	m_iCpuSum = 0;
	for(int i = 0;i < 15;i++)
		for(int j = 0;j < 15;j++)
		{
			m_iChess[i][j]=0;
			chess[i][j]=0;
			if(i<=7&&j<=7)
			{
				m_iCpuScore[i][j]=Min(i,j);
				m_iUserScore[i][j]=Min(i,j);
			}
			else if(i<=7)
			{
				m_iCpuScore[i][j]=Min(i,14-j);
				m_iUserScore[i][j]=Min(i,14-j);
			}
			else if(j<=7)
			{
				m_iCpuScore[i][j]=Min(14-i,j);
				m_iUserScore[i][j]=Min(14-i,j);
			}
			else
			{
				m_iCpuScore[i][j]=Min(14-i,14-j);
				m_iUserScore[i][j]=Min(14-i,14-j);
			}
		}
}

/*int * CStatistics::getNext(int chess[][15])
{
	int pos[4];
	int max=0,score,count=0,k,m;
	for(k=0;k<15;k++)
	{
		for(m=0;m<15;m++)
		{
			m_iChess[k][m]=chess[k][m];
			if(getScore(chess,k,m)>m_iCpuScore[k][m])
			{
				score = getScore(chess,k,m);
			}
			else
				score = m_iCpuScore[k][m];
			if(chess[k][m]==0&&score>=max)
			{
				max=score;
				pos[0]=k;
				pos[1]=m;
			}
		}
	}
	k=pos[0];
	m=pos[1];
	m_iChess[k][m] = 2;
	for(k=0;k<15;k++)
	{
		for(m=0;m<15;m++)
		{
			if(m_iChess[k][m]==0)
			{
				score = getScore(m_iChess,k,m);
				if(m_iCpuScore[k][m]>score)
					m_iCpuSum+=m_iCpuScore[k][m];
				else
					m_iCpuSum+=score;
			}
		}
	}
	k=pos[0];
	m=pos[1];
	max=0;
	for(k=0;k<15;k++)
	{
		for(m=0;m<15;m++)
		{
			m_iChess[k][m]=chess[k][m];
			if(getScore(chess,k,m)>m_iCpuScore[k][m])
			{
				score = getScore(chess,k,m);
			}
			else
				score = m_iCpuScore[k][m];
			if(chess[k][m]==0&&score>=max&&(k!=pos[0]&&m!=pos[1]))
			{
				max=score;
				pos[2]=k;
				pos[3]=m;
			}
		}
	}
	k=pos[2];
	m=pos[3];
	m_iChess[k][m] = 2;
	for(k=0;k<15;k++)
	{
		for(m=0;m<15;m++)
		{
			if(m_iChess[k][m]==0)
			{
				score = getScore(m_iChess,k,m);
				if(m_iCpuScore[k][m]>score)
					m_iUserSum+=m_iCpuScore[k][m];
				else
					m_iUserSum+=score;
			}
		}
	}
	if(m_iCpuSum<m_iUserSum)
	{
		pos[0]=pos[2];
		pos[1]=pos[3];
	}
	return pos;
}*/
