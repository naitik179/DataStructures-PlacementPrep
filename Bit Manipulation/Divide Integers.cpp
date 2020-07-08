/*

Divide two integers without using multiplication, division and mod operator.

Return the floor of the result of the division.

Example:

5 / 2 = 2
Also, consider if there can be overflow cases. For overflow case, return INT_MAX.

Note: INT_MAX = 2^31 - 1

*/



int Solution::divide(int A, int B) {
    
    if(B == 0){
        return INT_MAX;
    }
    long long a = A;
    long long b = B;
    
    if(A < 0){
        a = -a;
    }
    if(B < 0){
        b = -b;
    }
    
    long long res = 0;
    
    while(a >= b){
        
        long long sum = b;
        long long q = 1;
        
        while(sum + sum < a){
            sum = sum + sum;
            q = q+q;
        }
        
        a = a-sum;
        res = res + q;
    }
    
    if(A < 0){
        res = -res;
    }
    if(B < 0){
        res = -res;
    }
    
    if((int)res == res){
        return res;
    }
    else{
        return INT_MAX;
    }
    
}
