vector<vector<int> > Solution::anagrams(const vector<string> &A) {
    
    map<string , vector<int>>m;
    
    for(int i=0;i<A.size();i++){
        string str = A[i];
        sort(str.begin() , str.end());
        m[str].push_back(i+1);
    }
    vector<vector<int>>ans;
    for(auto it=m.begin() ; it!=m.end() ; it++){
        ans.push_back(it->second);
    }
    
    return ans;
}
/*

Example :

Input : cat dog god tca
Output : [[1, 4], [2, 3]]
    
*/