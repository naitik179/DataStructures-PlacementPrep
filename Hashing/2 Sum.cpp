vector<int> Solution::twoSum(const vector<int> &A, int B) {
    
                unordered_map<int,int> m;
                vector<int>ans;
                for (int i = 0; i < A.size(); i++){
                    
                    if(m.find(B - A[i]) != m.end()){
                        ans.push_back(m[B - A[i]] +1);
                        ans.push_back(i+1);
                        break;
                    }
                    else{
                        m.insert(make_pair(A[i] ,i));
                    }
                }
                return ans;
}
