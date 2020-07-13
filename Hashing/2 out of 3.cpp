vector<int> Solution::solve(vector<int> &A, vector<int> &B, vector<int> &C) {
    
    vector<int>ans;
    map<int , set<int>>m;

    for(int i=0;i<A.size();i++){
            m[A[i]].insert(1);
    }
    
    for(int i=0;i<B.size();i++){
            m[B[i]].insert(2);
    }
    
    for(int i=0;i<C.size();i++){
            m[C[i]].insert(3);
    }
    
    for(auto it= m.begin() ; it!=m.end();it++){
        if(it->second.size() >=2){
            ans.push_back(it->first);
        }
    }
    
    sort(ans.begin() , ans.end());
    return ans;
}

/*

Problem Description

Given are Three arrays A, B and C.

Return the sorted list of numbers that are present in atleast 2 out of the 3 arrays.

*/