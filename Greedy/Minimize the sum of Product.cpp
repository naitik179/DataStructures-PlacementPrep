#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int main() {
	//code
	long long int t;
	cin>>t;
	while(t--){
	    long long int n;
	    cin>>n;
	    long long int a[n];
	    long long int b[n];
	    
	    for(long long int i=0;i<n;i++){
	        cin>>a[(int)i];
	    }
	    
	    for(long long int j=0;j<n;j++){
	        cin>>b[(int)j];
	    }
	    
	    sort(a , a+n);
	    sort(b , b+n , greater<long long int>());
	    
	    long long int ans=0;
	    for(long long int i=0;i<n;i++){
	        ans+= (a[(int)i]*b[(int)i]);
	    }
	    
	    cout<<ans<<"\n";
	}
}