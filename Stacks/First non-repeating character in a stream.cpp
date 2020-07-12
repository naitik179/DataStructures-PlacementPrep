#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int main() {
	//code
	ios_base::sync_with_stdio(0); cin.tie(0);
    int t; cin>>t;
    while(t--)
    {
     vector<char>v;
     int n; cin>>n; char s[n]; int h[26]={0};
     for(int i=0;i<n;i++)
     {
         int k=-1;
         cin>>s[i]; h[s[i]-'a']++; v.push_back(s[i]);
         
         for(int j=0;j<v.size();j++)
         {
         if(h[v[j]-'a']==1) { k=1;cout<<v[j]<<" "; break;}
         }
         if(k==-1) cout<<k<<" ";
     }
     cout<<endl;
    }
	return 0;
}

/////////////////////////////////////// another Approach faster using Queue

string Solution::solve(string A) {
    
    int n = A.size();
    vector<int> repeated(26,0);
    string res="";
    deque<char> q;
    
    for(int i = 0; i < n; i++){
        if(repeated[A[i]-'a']==0){
            q.push_back(A[i]);
        }
        repeated[A[i]-'a']++;
        while(!q.empty() && repeated[q.front()-'a']>1){
            q.pop_front();
        }
        
        if(q.empty()){
            res+='#';
        }
        else{
            res+=q.front();
        }
    }
    
    return res;
}
