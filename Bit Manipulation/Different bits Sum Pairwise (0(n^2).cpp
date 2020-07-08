int f(int x , int y){
    
    int res = x ^ y;
    
    int c = 0;
    while(res){
        c += res & 1;
        res = res>>1;
    }
    
    return c;
}

int Solution::cntBits(vector<int> &A) {
    
    long long int n = A.size();
    long long int i = 0;
    long long int count = 0;
    
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            count = (count +  f(A[i] , A[j]))%1000000007;
        }
    }
    
    return (2*count);
}
