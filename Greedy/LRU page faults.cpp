#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n;
        int pf = 0;
        int a[n];
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        cin>>k;
        unordered_set<int>s;
        unordered_map<int ,int>m;
        
        for(int i=0;i<n;i++){
            
            if(s.find(a[i]) == s.end() && s.size()<k){
                s.insert(a[i]);
                pf++;
                m[a[i]] = i;
            }
            // set is full 
            else{
                // not in set then delete the first least one 
                if(s.find(a[i]) == s.end())
                {
                    int mini = INT_MAX;
                    int key;
                    for(auto it = s.begin() ; it!=s.end();it++){
                        if (m[*it] < mini) 
                        { 
                        mini = m[*it]; 
                        key = *it; 
                        } 
                    }
                    
                    s.erase(key);
                    s.insert(a[i]);
                    pf++;
                    m[a[i]] = i;
                }
                else{
                    m[a[i]] = i;
                }
            }
        }
        cout<<pf<<"\n";
    }
	return 0;
}