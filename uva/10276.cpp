#include <iostream>
using namespace std;
int main(int argc, char const *argv[])
{
	int t;
	cin>>t;
	while (t--)
	{
		int n;
		cin>>n;
		cout<<((n+1)*(n+1))/2-1<<"\n";
	}
	return 0;
}