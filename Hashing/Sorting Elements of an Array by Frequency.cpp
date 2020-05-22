// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

int a[1000000];

void sortByFreq(int arr[],int n);
int main() {
	
	int t;
	cin >> t;
	
	
	while(t--){
	  
	    int n;
	    cin >> n;
	    
	    for(int i = 0;i<n;i++){
	        cin >> a[i];
	    }
	    
	    sortByFreq(a,n);
	    cout << endl;
	}
	
	return 0;
}

bool comp(pair<int , int>p1 , pair<int , int>p2){
    if(p1.second == p2.second){
        return p1.first < p2.first;
    }
    else{
        return p1.second > p2.second;
    }
}

void sortByFreq(int arr[],int n)
{
    unordered_map<int , int>m;
    vector<pair<int , int>>v;
    
    for(int i=0;i<n;i++){
        m[arr[i]]++;
    }
    
    for(auto it=m.begin();it!=m.end();it++){
        v.push_back(make_pair(it->first , it->second));
    }
    
    sort(v.begin() , v.end() , comp);
    for(int j = 0;j<v.size();j++){
        for(int h =0;h<v[j].second;h++)
        {
            cout<<v[j].first<<" ";
        }
    }
    
}