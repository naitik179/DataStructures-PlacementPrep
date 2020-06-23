#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int main() {
	//code
	int t;
	cin>>t;
	while(t--){
	    int n,k;
	    cin>>n>>k;
	    vector<int>v;
	    int ch;
	    for(int i =0;i<n;i++){
	        cin>>ch;
	        v.push_back(ch);
	    }
	    sort(v.begin() , v.end());
	    int c =0;
	    int s = 0;
	    for(int i=0;i<n;i++){
	        s += v[i];
	        if(s<k){
	            c++;
	        }
	        else{
	            break;
	        }
	    }
	    cout<<c<<"\n";
	}
	return 0;
}