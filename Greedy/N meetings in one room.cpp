/*
There is one meeting room in a firm. There are N meetings in the form of (S[i], F[i]) 
where S[i] is start time of meeting i and F[i] is finish time of meeting i.

What is the maximum number of meetings that can be accommodated in the meeting room?

In each separate line print the order in which the meetings take place separated by a space.


Input:
2
6
1 3 0 5 8 5
2 4 6 7 9 9
8
75250 50074 43659 8931 11273 27545 50879 77924
112960 114515 81825 93424 54316 35533 73383 160252  

Output:
1 2 4 5
6 7 1


*/

#include <iostream>
#include<bits/stdc++.h>
using namespace std;


bool comp(const pair<pair<int , int> , int>&a , const pair<pair<int ,int> , int>&b){
    if(a.first.second == b.first.second){
        return a.first.first < b.first.first;
    }
    else{
        return a.first.second < b.first.second;
    }
}
int main() {
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    
	    vector<int>st;
	    vector<int>end;
	    int ch;
	    
	    for(int i=0;i<n;i++){
	        cin>>ch;
	        st.push_back(ch);
	    }
	    
	    for(int i=0;i<n;i++){
	        cin>>ch;
	        end.push_back(ch);
	    }
	    
	    vector<pair<pair<int , int> , int>>v;
	    
	    for(int i=0;i<n;i++){
	        v.push_back(make_pair(make_pair(st[i] , end[i]) , i+1));
	    }
	    
	    
	    sort(v.begin() , v.end() , comp);
	    
	    int endtime = 0;
	    for(int s=0;s<n;s++){
	        if(v[s].first.first >= endtime){
	            endtime = v[s].first.second;
	            cout<<v[s].second<<" ";
	        }
	    }
	    
	    cout<<"\n";
	    
	}
	return 0;
}