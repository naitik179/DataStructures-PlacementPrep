int Solution::removeElement(vector<int> &A, int B) {
    
    int n = A.size();
    
    int i=0;
    int j=0;
    for(int i=0;i<n;i++){
        if(A[i] != B){
            A[j] = A[i];
            j++;
        }
    }
    
    A.erase(A.begin() + j , A.end());
    return A.size();
    
    
}

/*

Remove Element

Given an array and a value, remove all the instances of that value in the array.
Also return the number of elements left in the array after the operation.
It does not matter what is left beyond the expected length.

 Example:
If array A is [4, 1, 1, 2, 1, 3]
and value elem is 1,
then new length is 3, and A is now [4, 2, 3] 
Try to do it in less than linear additional space complexity.

*/