vector<vector<int> > Solution::threeSum(vector<int> &A) {
    
    int n = A.size();
    sort(A.begin() , A.end());
    
    int flag =0;
    int l=0;
    int r=0;
    vector<vector<int>>ans;
    for(int i=0;i<n-2;i++){
        // fixing a[i]
        l = i+1;
        r = n-1;
        while(l<r){
            
            int currsum = A[i] + A[l] + A[r];
            if(currsum == 0){
                vector<int>v;
                v.push_back(A[i]);
                v.push_back(A[l]);
                v.push_back(A[r]);
                ans.push_back(v);
                v.clear();
                l++;
                r--;
            }
            if(currsum < 0){
                l++;
            }
            else{
                r--;
            }
        }
    }
    
    return ans;
}
