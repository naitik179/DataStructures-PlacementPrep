#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--){
	    int n,m;
	    cin>>n>>m;
	    long long sum1, sum2;
	    sum1=0;
	    sum2=0;
	    
	    int a[n];
	    int b[m];
	    int i,j;
	    for(i=0;i<n;i++){
	        cin>>a[i];
	    }
	    
	    for(j = 0;j<m;j++){
	        cin>>b[j];
	    }
	    i=0;
	    j=0;
	    long long ans=0;
	    while(i < n && j < m)
	    {
	        if(a[i] < b[j]){
	            sum1 += a[i++];
	        }
	        else if(b[j] < a[i]){
	            sum2 += b[j++];
	        }
	        else{
	            // equal
	            ans += max(sum1,sum2) + a[i];
	            sum1 =0;
	            sum2 =0;
	            int temp=a[i];
                ++i;
                temp=b[j];
                ++j;
                while(i<n && a[i]==temp)
                  ans+=a[i++];
                while(j<m && b[j]==temp)
                  ans+=b[j++];
	        }
	    }
	    while(i<n){
	        sum1 += a[i++];
	    }
	    while(j<m){
	        sum2 += b[j++];
	    }
	    
	    ans += max(sum1 , sum2);
	    
	    cout<<ans<<"\n";
	}
	
}