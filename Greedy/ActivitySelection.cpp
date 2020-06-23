/*
Given N activities with their start and finish times. Select the maximum number of activities that can be performed 
by a single person, assuming that a person can only work on a single activity at a time.

Note : The start time and end time of two activities may coincide

*/


#include <iostream>
#include<bits/stdc++.h>
using namespace std;


bool comp(const pair<int , int>&a , const pair<int , int>&b){
    if(a.second == b.second){
        return a.first < b.first;
    }
    else{
        return a.second < b.second;
    }
}
int main() {
	//code
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    int ch;
	    vector<int>st;
	    vector<int>end;
	    for(int i=0;i<n;i++){
	        cin>>ch;
	        st.push_back(ch);
	    }
	    
	    for(int i=0;i<n;i++){
	        cin>>ch;
	        end.push_back(ch);
	    }
	    
	    vector<pair<int , int>>a;
	    for(int i=0;i<n;i++){
	        a.push_back({st[i] , end[i]});
	    }
	    
	    
	    sort(a.begin(), a.end() , comp);
	    
	    int jd=0;
	    int starttime=0;
	    int endtime=0;
	    for(auto it = a.begin() ; it!= a.end() ; it++){
	        if(it->first >= endtime){
	            jd++;
	            endtime = it->second;
	        }
	    }
	    
	    cout<<jd<<"\n";
	    
	    
	}
	return 0;
}