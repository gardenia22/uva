#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <queue>
#include <algorithm>
#include <cstring> 
using namespace std;

int flow[105][105];
int co[105][105];
int degree[105];
int maxp[105];
int n,r,s,d,t;
fstream inFile;

void initialize();
bool input();

int main()
{
	
	inFile.open("10099.in");
	initialize();
	int count = 0;
	while (input())
	{
        count++;
		queue<int > Q;
		Q.push(s);
		for (int i=0;i<degree[s];i++) 
            maxp[s] = max(maxp[s],flow[s][co[s][i]]);
		while (!Q.empty())
		{
			int now = Q.front();
			Q.pop();
			for (int i=0;i<degree[now];i++)
			{
				int next = co[now][i];
				if (min(flow[now][next],maxp[now])>maxp[next])
				{
					maxp[next] = min(flow[now][next],maxp[now]);
					Q.push(next);
				}
			}
        }
		
//        for (int i=1;i<=n;i++) cout<<i<<" "<<maxp[i]<<endl;
        cout<<"Scenario #"<<count<<endl;
        cout<<"Minimum Number of Trips = ";
		if (t%(maxp[d]-1)==0) cout<<t/(maxp[d]-1)<<endl;
		else cout<<t/(maxp[d]-1)+1<<endl;
		cout<<endl;
		initialize();
	}
	return 0;

}

void initialize()
{
	//memset(flow,0,sizeof(flow));
	//memset(co,0,sizeof(co));
	memset(degree,0,sizeof(degree));
	memset(maxp,0,sizeof(maxp));
}

bool input()
{
	inFile>>n>>r;
//	cin>>n>>r;
	if ((n==0)&(r==0)) return false;
	int i;
	int c1,c2,p;
	for (i=0;i<r;i++)
	{
		inFile>>c1>>c2>>p;
		//cin>>c1>>c2>>p;
		flow[c1][c2] = p;
		flow[c2][c1] = p;
		co[c1][degree[c1]] = c2;
		degree[c1]++;
		co[c2][degree[c2]] = c1;
		degree[c2]++;
	}
	inFile>>s>>d>>t;
//	cin>>s>>d>>t;
	return true;
}
