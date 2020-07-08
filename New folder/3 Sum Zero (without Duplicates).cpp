vector<vector<int> > Solution::threeSum(vector<int> &A) {
    
    if(A.size()<3) return {};
    int n = A.size();
    sort(A.begin() , A.end());
    
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
                sort(v.begin() , v.end());
                if(find(ans.begin() , ans.end() , v) == ans.end()){
                    ans.push_back(v);    
                }
                l++;
                r--;
            }
            else if(currsum < 0){
                l++;
            }
            else{
                r--;
            }
        }
    }
    return ans;
}
