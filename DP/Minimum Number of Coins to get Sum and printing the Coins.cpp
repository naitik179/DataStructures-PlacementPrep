#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int main() {
	long long t;
	cin>>t;
	while(t--){
	    long long n;
	    cin>>n;
	    
	    long long first[n];
	    long long coins[10] ={1,2,5,10,20,50,100,200,500,2000};
	    long long dp[n+1];
	    
	    dp[0] = 0;
	    
	    for(int i=1;i<=n;i++){
	        dp[i] = INT_MAX;
	        for(int j=0;j<10;j++){
	            if(i >= coins[j] && dp[i - coins[j]] +1  < dp[i]){
	                dp[i] = dp[i - coins[j]] +1;
	                first[i] = coins[j];
	            }
	        }
	    }
	   
	    
	    deque<long long>dq;
	    while(n > 0){
	        dq.push_front(first[n]);
	        n -= first[n];
	    }
	    
	    for(int i=0;i<dq.size();i++){
	        cout<<dq[i]<<" ";
	    }
	    cout<<"\n";
	    dq.clear();
	}
}