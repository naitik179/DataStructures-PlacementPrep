void Solution::sortColors(vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    int n = A.size();
    int l=0;
    int curr = 0;
    int r = n-1;
    
    while(curr<=r){
        if(A[curr] == 0){
            swap(A[l++] , A[curr++]);
        }
        else if(A[curr] == 2){
            swap(A[curr] , A[r--]);
        }
        else{
            curr++;
        }
    }
}
