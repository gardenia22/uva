#include <iostream>
#include <stdio.h> 
#include <cstring> 
using namespace std;
int main()
{
	long i,j;
	
	while (cin>>i>>j) 
	{
        
        
		long ans = 0;
		long temp;
   		long ii = i;
        long jj = j;
		if (i>j)
		{
            temp = i;
            i = j;
            j = temp;
        }
        bool visit[j-i+2];
        memset(visit, true, sizeof(visit));
		for (long k = i;k <= j;k++)
		if (visit[k-i])
        {
			long now = k;
			long times = 0;
			while (now!=1)
			{
				times++;
				
				if (now%2==0)
				{
					now = now/2;
					visit[k-i]=false;
				}
				else
				{
					now = now*3 +1;
					visit[k-i]=false;
				}
			}
			if (times > ans) ans = times;
		}
		cout<<ii<<" "<<jj<<" "<<ans+1<<endl;
	}
	return 0;
}
