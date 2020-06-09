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
	    int maxvalue = 0;
	    
	    int a[n];
	    for(int i=0;i<n;i++){
	        cin>>a[i];
	        maxvalue = max(a[i] , maxvalue);
	    }
        
	    int ans = 0;
	    int freq[maxvalue+1] = {0};
	    
	    for(int i=0;i<n;i++){
	        freq[a[i]]++;
	    }
	     // case 1 0 0 0
	     ans += freq[0] * (freq[0] -1) * (freq[0] - 2) /6;
	   
	     
	     // case 1 0 x x
	     for(int i=1;i<=maxvalue;i++){
	         ans += freq[0] * freq[i] * (freq[i] -1) /2;
	      
	     }
	     // case 2 x x 2x
	     for(int i=1;2*i<=maxvalue;i++){
	       ans += freq[i] * (freq[i] -1) * freq[2*i] /2;
	    
	     }
	     // case 3 x y x+y
	     for(int i=1;i<=maxvalue;i++){
	         for(int j=i+1;j+i<=maxvalue;j++){
	            ans += freq[i] * freq[j] * freq[i+j];
	           
	         }
	     }
	     if(ans > 0){
	         cout<<ans<<"\n";
	     }
	     else{
	         cout<<"-1"<<"\n";
	     }
	}
}