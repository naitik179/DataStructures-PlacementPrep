unsigned int Solution::reverse(unsigned int A) {
    

    int ans = 0;
    for(int i=0;i<32;i++){
        
        if(A & (1<<i)){
            ans += pow(2 , 31-i);
        }
    }
    
    return ans;
}

/*

Reverse the bits of an 32 bit unsigned integer A.


Input Format
First and only argument of input contains an integer A.



Output Format
Return a single unsigned integer denoting the decimal value of reversed bits.



Example Input
Input 1:

 0
Input 2:

 3


Example Output
Output 1:

 0
Output 2:

 3221225472


Example Explanation
Explanation 1:

        00000000000000000000000000000000

=>      00000000000000000000000000000000
Explanation 2:

        00000000000000000000000000000011    
=>      11000000000000000000000000000000


*/