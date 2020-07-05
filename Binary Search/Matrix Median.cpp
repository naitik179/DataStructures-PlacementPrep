int Solution::findMedian(vector<vector<int>> &A) {
    
    int start = A[0][0], end = A[0][0];
    int rows = A.size(), cols = A[0].size();
    int target = (rows*cols+1)/2, count, mid;
    for(int i = 0; i < rows; i++){
        start = min(start, A[i][0]);
        end = max(end, A[i][cols-1]);
    } 
    while(start < end){
        count = 0;
        mid = (start+end)/2;
        for(int i = 0; i < rows; i++){
            count += upper_bound(A[i].begin(), A[i].end(), mid)-A[i].begin();
        }
        //cout<<"count is "<<count<<endl;
        if(count >= target){
            end = mid;
        }
        else start = mid+1;
    }
    return start;
}
