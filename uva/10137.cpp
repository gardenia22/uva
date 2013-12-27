#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
	int n;
	cin>>n; 
	while (n!=0)
	{	
		float a[n];
		float sum = 0;
		for (int i=0;i<n;i++)
		{
			cin>>a[i];
			sum += a[i];
		}
		float avg = sum/n;
		cout<<avg<<endl;
		int temp = int(avg*1000);
		int remain = temp%10;
		if (remain>4) 
           avg = (float)(temp-remain+10)/1000;
        else 
           avg = (float)(temp-remain)/1000;
		cout<<remain<<" "<<temp<<" "<<avg<<endl;
		float ans = 0;
		for (int i=0;i<n;i++)
		{
			if (a[i]-avg>0)
               ans +=a[i]-avg;
            else    
               ans +=avg-a[i];
		}
		ans = ans/2;
		cout<<"$"<<fixed<<setprecision(2)<<ans<<endl;
		cin>>n;
	}
	return 0;
}
