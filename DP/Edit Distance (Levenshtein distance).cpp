#include <iostream>
#include<bits/stdc++.h>
using namespace std;
int mini(int x ,int y , int z){
    return min(min(x,y) , z);
}
int main() {
	//code
	int t;
	cin>>t;
	while(t--){
	    string s1 , s2;
	    int n , m;
	    cin>>n>>m;
	    cin>>s1;
	    cin>>s2;
	    
	    int dp[n+1][m+1];
	    
	    for(int i=0;i<=n;i++){
	        for(int j=0;j<=m;j++){
	            if(i==0){
	                dp[i][j] = j;
	            }
	            else if(j==0){
	                dp[i][j] = i;
	            }
	            else if(s1[i-1] == s2[j-1]){
	                dp[i][j] = dp[i-1][j-1];
	            }
	            else{
	                dp[i][j] = 1 + mini(dp[i][j - 1], // Insert 
                                   dp[i - 1][j], // Remove 
                                   dp[i - 1][j - 1]); // Replace 
	            }
	        }
	    }
	    
	    cout<<dp[n][m]<<"\n";
	}
}	