#include <iostream>
#include<bits/stdc++.h>
using namespace std;
int memo[100][100];

int osrec(int a[] , int i , int j , int sum){
    
    if(i+1 == j){
        return max(a[i] , a[j]);
    }
    
    if(memo[i][j] != -1){
        return memo[i][j];
    }
    
    memo[i][j] = max(sum - osrec(a , i+1 , j , sum - a[i]),
                     sum - osrec(a , i , j-1 , sum - a[j]));
                     
    return memo[i][j];
}
int main() {
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    
	    int a[n];
	    for(int i=0;i<n;i++){
	        cin>>a[i];
	    }
	    
	    
	    memset(memo , -1 , sizeof(memo));
	    
	    int sum = 0;
	    
	    sum = accumulate(a , a+n , sum);
	    
	    int ans = osrec(a , 0 , n-1 , sum);
	    
	    cout<<ans<<"\n";
	}
}