int Solution::firstMissingPositive(vector<int> &A) {
    int isone = 0;
    int n = A.size();
    
    for(int i=0;i<n;i++){
        if(A[i] == 1){
            isone = 1;
        }
        else if(A[i] <= 0 || A[i] > n){
            A[i]  = 1;
        }
    }
    
    if(isone == 0){
        return 1;
    }
    int flag = 0;
    for(int i=0;i<n;i++){
        int index = abs(A[i]) - 1;
        
        if(A[index] >0){
            A[index] = -1*A[index];
        }
    }
    
    for(int i=0;i<n;i++){
        if(A[i] > 0){
            return i+1;
        }
        else{
            flag++;
        }
    }
    if(flag == n){
        return n+1;
    }
}
