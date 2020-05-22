#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

vector<int> TopK(vector<int>& array, int k) ;

bool comp(pair<int , int>p1 , pair<int , int>p2){
    if(p1.second == p2.second){
        return p1.first > p2.first;
    }
    else{
        return p1.second > p2.second;
    }
}

vector<int> TopK(vector<int>& array, int k) 
{
   unordered_map<int , int>m;
   vector<pair<int , int>>v;
   vector<int>ans;
   
   for(auto it = array.begin();it!=array.end();it++){
       m[*it]++;
   }
   
   for(auto it = m.begin();it!=m.end();it++){
       v.push_back(make_pair(it->first , it->second ));
   }
   
   sort(v.begin() , v.end() , comp);
   
   for(int i=0;i<k;i++){
       ans.push_back(v[i].first);
   }
   
   return ans;
   
}


int main(){
    int t;
    cin>>t;
    while(t--)
    {
        int n,k ;
        cin>>n;
        vector <int> array(n);

        for(int i=0; i<n; i++)
            cin>>array[i];
        cin>>k;

        vector<int> result = TopK(array,k);
        
        for(int i=0; i<result.size();i++)
            cout<<result[i]<<" ";

        cout<<"\n";

    }
    return 0;
}  