int Solution::findMin(const vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

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
