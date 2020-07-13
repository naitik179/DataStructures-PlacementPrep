vector<int> Solution::lszero(vector<int> &A) {
    
    unordered_map<int  , int>m;
    int sum = 0;
    int max = INT_MIN;
    int start = 0;
    int end;
    vector<int>ans;
    for(int i=0;i<A.size();i++){
        
        sum += A[i];
        if(sum== 0){
            if(i +1 > max){
                max = i+1;
                start = 0;
                end = i;
            } 
        }
        else if(m.find(sum) != m.end()){
            if(i - m[sum] > max){
                start = m[sum]+1;
                end = i;
                max = i - m[sum];
            }
        }
        
        else{
            m[sum] = i;
        }
    }
    
    if(max==INT_MIN)
        return ans;
    else
    {
        for(int i=start;i<=end;i++)
        {
            ans.push_back(A[i]);
        }
        return ans;
    }
}
