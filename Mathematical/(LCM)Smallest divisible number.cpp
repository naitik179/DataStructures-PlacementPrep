#include <bits/stdc++.h>
using namespace std;

long long getSmallestDivNum(long long n);

int main() {
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		cout<<getSmallestDivNum(n)<<endl;
	}
	return 0;
	
}

long long lcm(long long a,long long b)
{
    long long lar = max(a, b); 
    long long small = min(a, b); 
    for (long long i = lar; ; i += lar) { 
        if (i % small == 0) 
            return i; 
    } 
} 

long long getSmallestDivNum(long long n)
{
    long long ans=1;
    long long gc;
    for(int i=1;i<=n;i++)
    {
       ans = lcm(ans , i);
    }
    return ans;
}
