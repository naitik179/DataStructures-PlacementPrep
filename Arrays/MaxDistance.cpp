int Solution::maximumGap(const vector<int> &A) {
    int ans = 0;
    
    int l[A.size()];
    int r[A.size()];
    
    int mini = A[0];
    int maxi = A[A.size()-1];
    l[0] = mini;
    r[A.size()-1] = maxi;
    
    for(int i=1;i<A.size();i++){
        mini = min(mini , A[i]);
        l[i] = mini;
    }
    for(int j=A.size()-2;j>=0;j--){
        maxi = max(A[j] , maxi);
        r[j] = maxi;
    }
    int i=0;
    int j=0;
    while(i<A.size() && j<A.size()){
        if(l[i] <= r[j]){
            ans  = max(ans , j-i);
            j++;
        }
        else{
            i++;
        }
    }
    return ans;
}
