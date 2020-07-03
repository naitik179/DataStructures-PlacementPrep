#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--){
	    long long n;
	    cin>>n;
	    long long a[n];
	    
	    for(int i=0;i<n;i++){
	        cin>>a[i];
	    }
	    long long l[n]; // left max
	    long long r[n]; // rigt max
	    long long count=0;
	    
	    l[0] = a[0];
	    r[n-1] = a[n-1];
	    
	    for(int i=1;i<n;i++){
	        l[i] = max(l[i-1] , a[i]);
	    }
	    
	    for(int j=n-2;j>=0;j--){
	        r[j] = max(r[j+1] , a[j]);
	    }
	    
	    for(int i=0;i<n;i++){
	        long long temp = min(l[i] , r[i]);
	        if(temp > a[i]){
	            count += temp - a[i];
	        }
	    }
	    
	    cout<<count<<"\n";
	}
	return 0;
}