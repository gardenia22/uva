#include <stdlib>
#include <fstream>
#include <iostream>
#include <cstring>
#define MAXINT 250
using namespace std;

struct position
{
	int x;
	int y;/* data */
}position;
bool map[MAXINT][MAXINT];
bool visit[MAXINT][MAXINT];
int n,m;

input();

int main()
{

	input();
	int t = 0;
	while (true)
	{
		t++;
		if ((n==0)&(m==0))
			break;
		int ring = 0;
		int ans = 0;
		int count = 0;
		for (int i=0;i<n;i++)
			for (int j=0;j<n;j++)
				if ((map[i][j])&(visit[i][j]))
				{
					position start,now,next;
					start.x = i;start.y = j;
					queue<position> Q;
					Q.push(start);
					count = 1;
					while (!Q.empty())
					{
						now = Q.front();
						Q.pop();
						for (int i=0;i<4;i++)
						{
							next.x = now.x+direx[i];
							next.y = now.y+direy[i];
							if (next.x<n && next.x>=0 && next.y>=0 &&next.y<m)
							if ((map[next.x][next.y])&(visit[i][j]))
							{
								Q.push(next);
								count++;
								visit[i][j] = false;
							}
						}
					}
					for (int i=0;i<4;i++)
						{
							next.x = now.x+direx[i];
							next.y = now.y+direy[i];
							if ((next.x==start.x)&(next.y==start.y))
							{
								if (count>ans) 
									ans = count;
								ring++;
							}
								
						}
					cout<<"Maze #"<<t<<endl;
					cout<<ring<<" Cycles; the longest has length "<<ans<<endl;
					cout<<endl;

				}
		input();
	}
	return 0;


}


void input()
{
	cin>>n>>m;
	char ch;
	memset(map,true,sizeof(map));
	for (int i=0;i<n;i++)
		for (int j=0;j<m;j++)
		{
			cin>>ch;
			if (ch=='/')
			{
				map[i*3][j*3+2] = false;
				map[i*3+1][j*3+1] = false;
				map[i*3+2][j*3] = false;
			}
			else
			{
				map[i*3][j*3] = false;
				map[i*3+1][j*3+1] = false;
				map[i*3+2][j*3+2] = false;
			}
		}

}
