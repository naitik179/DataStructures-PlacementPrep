int Solution::minimize(const vector<int> &A, const vector<int> &B, const vector<int> &C) {
    
    int diff = INT_MAX;
    
    int p = A.size(),q = B.size() , r = C.size();
    
    int i,j,k;
    int res_i , res_j,res_k;
    while(i<p && j<q && k<r){
        int mini = min(A[i] , min(B[j] , C[k]));
        int maxi = max(A[i] , max(B[j] , C[k]));
        
        if(maxi - mini < diff){
            diff = maxi - mini;
            res_i = i;
            res_j = j;
            res_k = k;
        }
        
        if(diff == 0){
            break;
        }
        
        if (A[i] == mini) i++; 
        else if (B[j] == mini) j++; 
        else k++;
    }
    
    return diff;
}

/*

Refer https://www.geeksforgeeks.org/find-three-closest-elements-from-given-three-sorted-arrays/


You are given 3 arrays A, B and C. All 3 of the arrays are sorted.

Find i, j, k such that :
max(abs(A[i] - B[j]), abs(B[j] - C[k]), abs(C[k] - A[i])) is minimized.
Return the minimum max(abs(A[i] - B[j]), abs(B[j] - C[k]), abs(C[k] - A[i]))

**abs(x) is absolute value of x and is implemented in the following manner : **

      if (x < 0) return -x;
      else return x;
Example :

Input : 
        A : [1, 4, 10]
        B : [2, 15, 20]
        C : [10, 12]

Output : 5 
         With 10 from A, 15 from B and 10 from C. 

*/