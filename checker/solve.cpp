#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin>>n;
	vector<int> V(n);
	long long sum = 0;
	for(auto &u : V)
	{
		cin>>u;
		sum+=u;
	}
	sort(V.begin(), V.end());
	long long halfsum = 0;
	int I = -1;
	for(int i = 0; i < n; i ++)
	{
		halfsum += V[i];
		if(halfsum*2 == sum)
		{
			I = i;
			break;
		}
	}
	if(I == -1)
	{
		cout<<"NIE\n";
		return 0;
	}
	cout<<"TAK\n"<<I+1<<" "<<n-I-1<<"\n";
	for(int i = 0 ;i < n ;i ++)
	{
		cout<<V[i]<<" ";
		if(i == I)
			cout<<"\n";
	}
    cout<<"\n";

}