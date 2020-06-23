#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin>>t;
	
	while(t--){
	    int n,k;
	    cin>>n>>k;
	    
	    int ch;
	    vector<int>v;
	    for(int i=0;i<n;i++){
	        cin>>ch;
	        v.push_back(ch);
	    }
	    sort(v.begin() , v.end());
	    
	    int count = 0;
	    int temp = 0;
	    int min1;
	    int result = INT_MAX;
	    int max1;
	    
	    for(int i=0;i<n;i++){
	        count = temp;
	        temp += v[i];
	        min1 = v[i];
	        for(int j=n-1;j>i;j--){
	            max1 = v[j];
	            if(max1 - min1 > k){
	                count += (max1-min1-k);
	            }
	        }
	        
	        result = min(result ,count);
	    }
	    
	    cout<<result<<"\n";
	}
	return 0;
}