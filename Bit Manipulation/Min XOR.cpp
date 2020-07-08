/*

Given an integer array A of N integers, find the pair of integers in the array which have minimum XOR value. Report the minimum XOR value.

Input Format:

    First and only argument of input contains an integer array A
Output Format:

    return a single integer denoting minimum xor value


    For Examples :

	Example Input 1:
	    A = [0, 2, 5, 7]
	Example Output 1:
	    2
	Explanation:
	    0 xor 2 = 2
	Example Input 2:
	    A = [0, 4, 7, 9]
	Example Output 2:
	    3


*/


int Solution::findMinXor(vector<int> &A) {
    
    int n = A.size();
    sort(A.begin() , A.end());
    int mini = INT_MAX;
    for(int i=0;i<n-1;i++){
        int res = A[i] ^ A[i+1];
        mini = min(mini , res);
    }
    
    return mini;
}
