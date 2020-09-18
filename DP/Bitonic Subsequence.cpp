#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int main() {
	//code
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    int a[n];
	    for(int i=0;i<n;i++){
	        cin>>a[i];
	    }
	    
	    int lis[n] , lds[n];
	    for(int i=0;i<n;i++){
	        lis[i] = 1;
	        lds[i] = 1;
	    }
	    
	    for(int i=1;i<n;i++){
	        for(int j=0;j<i;j++){
	            if(a[i] > a[j] && lis[i] < lis[j]+1){
	                lis[i] = lis[j]+1;
	            }
	        }
	    }
	    
	    for(int i=n-2;i>=0;i--){
	        for(int j=n-1;j>i;j--){
	            if(a[i] > a[j] && lds[i] < lds[j]+1){
	                lds[i] = lds[j]+1;
	            }
	        }
	    }
	    
	    int maxi = lis[0] + lds[0] -1;
	    for(int i=1;i<n;i++){
	        maxi = max(lis[i] + lds[i] -1,maxi); 
	    }
	    
	    cout<<maxi<<"\n";
	}
	return 0;
}