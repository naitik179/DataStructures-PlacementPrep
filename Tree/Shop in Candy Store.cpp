#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--){
	    int n,k;
	    cin>>n>>k;
	    
	    vector<int>v;
	    int ch;
	    for(int i=0;i<n;i++){
	        cin>>ch;
	        v.push_back(ch);
	    }
	    sort(v.begin() , v.end());
	    
	    int max=0;
	    int min=0;
	    int l=0;
	    int r = n;
	    while(l<r){
	        min += v[l];
	        l++;
	        r-=k;
	    }
	    
	    l=-1;
	    r=v.size()-1;
	    
	    
	    while(l<r){
	        max += v[r];
	        r--;
	        l+=k;
	    }
	    
	    cout<<min<<" "<<max<<"\n";
	}
	return 0;
}