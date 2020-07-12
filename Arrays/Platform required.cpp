#include <iostream>
#include<bits/stdc++.h>
using namespace std;

bool comp(const pair<int , char>&a , const pair<int  , char>&b){
    if(a.first == b.first){
        return a.second < b.second;
    }
    return a.first < b.first;
}
int main() {
	//code
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    int a[n] , d[n];
	    
	    for(int i=0;i<n;i++){
	        cin>>a[i];
	    }
	    for(int i=0;i<n;i++){
	        cin>>d[i];
	    }
	    
	    vector<pair < int , char>>v;
	    for(int i=0;i<n;i++){
	        v.push_back({a[i] , 'a'});
	        v.push_back({d[i] , 'd'});
	    }
	    
	    sort(v.begin(),v.end(),comp);
	    
	    int res =1;
	    int plat = 0;
	    
	    for(auto it = v.begin() ; it!=v.end(); it++){
	        if((*it).second == 'a'){
	            plat++;
	        }
	        else if((*it).second == 'd'){
	            plat--;
	        }
	        
	        if(plat > res){
	            res = plat;
	        }
	    }
	    
	    cout<<res<<"\n";
	}
	return 0;
}