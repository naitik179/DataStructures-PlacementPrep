#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int main() {
	//code
	int t;
	cin>>t;
	while(t--){
	    long long n;
	    long long flag;
	    cin>>n;
	    long long a[n];
	    for(long long i=0;i<n;i++){
	        cin>>a[(int)i];
	    }
	   
	    
	    if(n == 0 || a[0] == 0){
	        flag = -1;
	    }
	    else{
	         long long dp[n];
	         dp[0] = 0;
	         
	         for(long long i=1;i<=n;i++){
	             dp[(int)i] = INT_MAX;
	             for(long long j=0;j<i;j++){
	                 if(i <= j+a[(int)j] && dp[(int)j]!= INT_MAX){
	                     dp[(int)i] = min(dp[(int)i] , dp[(int)j] +1);
	                     break;
	                 }
	             }
	         }
	         if(dp[(int)n-1] == INT_MAX){
	             flag = -1;
	         }
	         else{
	             flag = dp[(int)n-1];
	         }
	    }
	    cout<<flag<<"\n";
	}
}