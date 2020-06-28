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
	    int sum=0;
	    for(int i=0;i<n;i++){
	        cin>>a[i];
	        sum+=a[i];
	    }
	    
	    bool dp[n+1][sum+1];
	    
	    for(int i=0;i<=n;i++){
	        dp[i][0] = true;
	    }
	    
	    for(int i=1;i<=sum;i++){
	        dp[0][i] = false;
	    }
	    
	    for(int i=1;i<=n;i++){
	        for(int j=1;j<=sum;j++){
	            if(j >= a[i-1]){
	                dp[i][j] = dp[i-1][j - a[i-1]] || dp[i-1][j];
	            }
	            else{
	                dp[i][j] = dp[i-1][j];
	            }
	        }
	    }
	    

	    // ********* IMPORTANT ***************
	    int max = INT_MAX;
	    
	    for(int j=sum/2;j>=0;j--){
	        if(dp[n][j] == true){
	            max = sum - 2*j;
	            break;
	        }
	    }
	    
	    
	    cout<<max<<"\n";
	    
	}
	return 0;
}

/*
So      
    dp[n+1][sum+1]  will be 1 if 
    1) The sum j is achieved including i'th item
    2) The sum j is achieved excluding i'th item.

Let sum of all the elements be S.  

To find Minimum sum difference, w have to find j such 
that Min{sum - j*2  : dp[n][j]  == 1 } 
    where j varies from 0 to sum/2

The idea is, sum of S1 is j and it should be closest
to sum/2, i.e., 2*j should be closest to sum.


*/