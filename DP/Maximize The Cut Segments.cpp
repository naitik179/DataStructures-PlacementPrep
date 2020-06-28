#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    int a[n];
	    set<int>s;
	    for(int i=0;i<3;i++){
	        cin>>a[i];
	        s.insert(a[i]);
	    }
	    vector<int>dp (n+1 , -1);
	    dp[0] = 0;
	    for(auto c: s){
	        for(int i=1;i<=n;i++){
	            if(i >= c && dp[i-c]!=-1){
	                dp[i] = max(dp[i] , dp[i-c] +1);
	            }
	        }
	    }
	    cout<<dp[n]<<"\n";
	    s.clear();
	    dp.clear();
	}
	return 0;
}