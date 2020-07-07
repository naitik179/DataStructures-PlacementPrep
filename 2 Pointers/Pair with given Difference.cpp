int Solution::solve(vector<int> &A, int B) {
    // int n = A.size();
    // sort(A.begin() , A.end());
    
    // int l;
    // int r;
    
    // if(n==2){
    //     if(A[1] - A[0] == B){
    //         return 1;
    //     }
    //     else{
    //         return 0;
    //     }
    // }
    // for(int i=0;i<n;i++){
    //     // fixing a[i]
    //     l = i+1;
    //     r = n-1;
    //     while(r>l){
    //         if(A[r] - A[i] == B || A[i] - A[i] == B){
    //             return 1;
    //         }
    //         else if(A[r] - A[i] > B){
    //             r--;
    //         }
    //         else if(A[l] - A[i] < B){
    //             l++;
    //         }
    //     }
    // }
    
    unordered_map<int  , int>m;
    int n = A.size();
    
    for(int i=0;i<n;i++){
        m[A[i]]++;
    }
    
    if(B==0){
        for(int i=0;i<n;i++){
            if(m[A[i]]>=2){
                return 1;
            }
        }
        return 0;
    }
    else{
    
    for(int i=0;i<n;i++){
        if(m[B + A[i]]){
            return 1;
        }
    }
    }
    return 0;
}
