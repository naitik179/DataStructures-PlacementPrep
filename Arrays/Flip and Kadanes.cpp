/*

You are given a binary string(i.e. with characters 0 and 1) S consisting of characters S1, S2, …, SN. In a single operation, you can choose two indices L and R such that 1 ≤ L ≤ R ≤ N and flip the characters SL, SL+1, …, SR. By flipping, we mean change character 0 to 1 and vice-versa.

Your aim is to perform ATMOST one operation such that in final string number of 1s is maximised. If you don’t want to perform the operation, return an empty array. Else, return an array consisting of two elements denoting L and R. If there are multiple solutions, return the lexicographically smallest pair of L and R.

Notes:

Pair (a, b) is lexicographically smaller than pair (c, d) if a < c or, if a == c and b < d.
For example,

S = 010

Pair of [L, R] | Final string
_______________|_____________
[1 1]          | 110
[1 2]          | 100
[1 3]          | 101
[2 2]          | 000
[2 3]          | 001

We see that two pairs [1, 1] and [1, 3] give same number of 1s in final string. So, we return [1, 1].
Another example,

If S = 111

No operation can give us more than three 1s in final string. So, we return empty array [].

*/



vector<int> Solution::flip(string A) 
{
    long long int maxsofar = 0;
    long long int maxendhere = 0;
    int i =0,j =0 ,start=-1,end=-1;
    
    for(i=0;i<A.size();i++){
        maxendhere += (A[i]=='1')?-1:1;
        if(maxsofar < maxendhere){
            maxsofar = maxendhere;
            start = j;
            end  = i;
        }
        if(maxendhere < 0){
            j=i+1;
            maxendhere = 0;
        }
    }
    vector<int>v;
    if(maxsofar){
        v.push_back((start+1));
        v.push_back((end+1));
    }
    return v;
}