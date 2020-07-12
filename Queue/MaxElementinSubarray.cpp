vector<int> Solution::slidingMaximum(const vector<int> &A, int k) {
    
    int l = A.size();
    deque<int>dq;
    vector<int>ans;
    
    for(int i=0;i<l;i++){
        while(!dq.empty() && A[i] >= A[dq.back()]){
            dq.pop_back();
        }
        
        dq.push_back(i);
        
        if(i >= k-1){
            ans.push_back(A[dq.front()]);
        }
        
        if(dq.front() <= i-k +1){
            dq.pop_front();
        }
    }
    
    return ans;
}
