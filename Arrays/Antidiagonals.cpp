vector<vector<int> > Solution::diagonal(vector<vector<int> > &A) {
    
    vector<vector<int>>v;
    map<int , vector<int>>m;
    
    
    for(int i=0;i<A.size();i++){
        for(int j=0;j<A[i].size();j++){
            m[i+j].push_back(A[i][j]);
        }
    }
    
    for(auto it =m.begin();it!=m.end();it++){
        v.push_back(it->second);
    }
    return v;

}


/*

Input : 
1 2
3 4

Return the following  : 

[
  [1],
  [2, 3],
  [4]
]





*/