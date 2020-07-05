int Solution::findCount(const vector<int> &A, int B) {
    
    int low=0;
    int high=A.size() -1;
    int mid;
    int result1,result2;
    while(low <= high){
        mid = (low + high)/2;
        
        if(A[mid] == B){
            result1 = mid;
            high = mid-1;
        }
        else if(A[mid] > B){
            high = mid -1;
        }
        else{
            low = mid + 1;
        }
    }
    
    low=0;
    mid = 0;
    high=A.size() -1;
    while(low <= high){
        mid = (low + high)/2;
        
        if(A[mid] == B){
            result2 = mid;
            low = mid+1;
        }
        else if(A[mid] > B){
            high = mid -1;
        }
        else{
            low = mid + 1;
        }
    }
    
    
    return result2 - result1 +1;
}


