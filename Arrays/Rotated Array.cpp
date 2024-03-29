int Solution::findMin(const vector<int> &A) {
    
    int n = A.size();
    int l = 0;
    int r = n-1;
    int mid;
    while(l<=r){
        if(A[l] <= A[r]){
            return A[l];
        }
        mid = (l+r)/2;
        int lowpos = (mid + n -1)%n;
        int highpos = (mid +1)%n;
        if(A[mid] <= A[lowpos] && A[mid] <= A[highpos]){
            return A[mid];
        }
        else if(A[mid] <= A[r]){
            r = mid -1;
        }
        else if(A[mid] >= A[r]){
            l = mid +1;
        }
    }
    
    return -1;
}

// Find the minimum element. form the rotated array 4 5 6 7 0 1 2