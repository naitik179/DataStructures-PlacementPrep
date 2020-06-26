#include <iostream>
#include<bits/stdc++.h>
using namespace std;

#define mod 1000000007
int main() {
	int t;
	cin>>t;
	while(t--){
	    int n,m;
	    cin>>n>>m;
	    
	    int dp[n][m];
	    
	    for(int i=0;i<n;i++){
	        dp[i][0] = 1;
	    }
	    for(int i=0;i<m;i++){
	        dp[0][i] = 1;
	    }
	    
	    for(int i=1;i<n;i++){
	        for(int j=1;j<m;j++){
	            dp[i][j] = (dp[i][j-1] + dp[i-1][j])%mod;
	        }
	    }
	    
	    cout<<dp[n-1][m-1]<<"\n";
	}

}