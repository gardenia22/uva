#include <stdlib>
#include <vector>
#include <fstream>
#include <iostrem>
#include <queue>
using namespace std;
typedef struct gear
{
	int top[4];/* data */
	int step;
}gear;

gear dire[8];


gear Begin;
gear End;
bool avoid[10000];
bool visited[10000];

gear readGear();
bool Compare(gear, gear);
gear Add(gear, gear);
int Getid(gear);


int main()
{
    dire[1].top = [0,0,0,1];
dire[2].top = [0,0,0,-1];
dire[3].top = [0,0,1,0];
dire[4].top = [0,0,-1,0];
dire[5].top = [0,1,0,0];
dire[6].top = [0,-1,0,0];
dire[7].top = [1,0,0,0];
dire[0].top = [-1,0,0,0];
	fstream inFile
	inFile.open("10067.in");
	int n;
	inFile>>n;
	for (int i=0;i<n;i++)
	{
		memset(avoid,false,sizeof(avoid));
		memset(visit,false,sizeof(visit));
		Begin = readGear();
		End = readGear();
		int m;
		inFile>>m;
		for (int j=0;j<m;j++)
		{
			gear Temp;
			Temp = readGear();
			avoid[Getid(Temp)] = true;
		}
		
		queue<gear> Q;
		Begin.step = 0;
		visit[Getid(Begin)] = true;
		Q.push(Begin);
		gear Now;
		gear Next;
		while (true)	
		{
			Now = Q.front();
			Q.pop();
			if (Compare(Now,End)) break;
			for (int i=0;i<8;i++)
			{
				Next = Add(Now,dire[i]);
				if ((!visited[Getid(next)])&(!avoid[Getid(Next)]))
				{
					Next.step = Now.step+1;
					visited[Getid(next)] = true;
					Q.push(Next);

				}
			}
		}
		Q.clear();
		Avoid.clear();
		cout>>End.step;
	}
	return 0;
}

gear readGear()
{
	gear read;
	for(int i=0;i<4;i++)
		inFile<<read.top[i]
	return read;
}

bool Compare(gear x, gear y)
{
	for (int i=0;i<4)
	{
		if (x.top[i]!=y.top[i])
			return false;
	}
	return true;
}
gear Add(gear x, gear y)
{
	gear ans;
	for (int i=0;i<4;i++)
	{
		ans.top[i] = x.top[i]+y.top[i];
		if (ans.top[i]==10)  ans.top[i] = 0;
		if (ans.top[i]==-1) ans.top[i] = 9;
	}
	return ans;
}

int Getid(gear x)
{
	int id = 0;
	for (int i=0;i<4;i++)
		id = id*10+ x.top[i];
	return id;
}
