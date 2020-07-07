#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    vector<string>v;
	    int x = INT_MAX;
	    int cnt = 0;
	    string ans = "";
	 
	    for(int i=0;i<n;i++){
	        string s;
	        cin>>s;
	        if(s.size() < x){
	            x = s.size();
	        }
	        v.push_back(s);
	    }
	    int flag= 0;
	    
	    for(int i=0;i<x;i++){
	        for(int j=0;j<v.size();j++){
	            if(v[0][i] != v[j][i]){
	                flag = 1;
	                break;
	            }
	        }
	        if(flag == 1){
	            break;
	        }
	        cnt++;
	        ans+=v[0][i];
	    }
	    if(cnt==0){
	        cout<<-1<<endl;
	    }
	    else{
	        cout<<ans<<endl;
	    }
	}
}