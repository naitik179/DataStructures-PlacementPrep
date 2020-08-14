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
	    
	    for(int i=0;i<n;i++){
	        cin>>a[i];
	    }
	    
	    int flag= 0;
	    
	    int i = 0;
	    while(i < n-1){
	        
	        while( i < n-1 && a[i] >= a[i+1]){
	            i++;
	        }
	        
	        if(i==n-1){
	            if(flag == 0){
	                cout<<"No Profit";
	            }
	            break;
	        }
	        int buy = i;
	        i++;
	        while(i<n && a[i] >= a[i-1]){
	            i++;
	        }
	        flag = 1;
	        int sell = i-1;
	        cout<<"("<<buy<<" "<<sell<<")"<<" ";
	    }
	    
	    cout<<"\n";
	}
	return 0;
}