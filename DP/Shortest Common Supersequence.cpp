#include<bits/stdc++.h>
const int mod=1e9+7;
using namespace std;

int lcs(string, string);

int main()
{
    int t,n,k;
    
    cin>>t;
    while(t--)
    {
        string s1,s2;
        cin>>s1>>s2;      
        cout << lcs(s1, s2) << endl;
    }
    return 0;
}

int lcs(string s1, string s2){
    
    int n = s1.length();
    int m = s2.length();
    
    int dp[n+1][m+1];
    
    for(int i=0;i<=n;i++){
        dp[i][0] = 0;
    }
    
    for(int i=0;i<=m;i++){
        dp[0][i]=0;
    }
    
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(s1[i -1] == s2[j -1]){
                dp[i][j] = dp[i-1][j-1] +1;
            }
            else{
                dp[i][j] = max(dp[i-1][j] , dp[i][j-1]);
            }
        }
    }
    
    return n+m-dp[n][m];
    
}


/*

Given two strings str1 and str2, find the length of the smallest string which has both, str1 and str2 as its sub-sequences.
Note: str1 and str2 can have both uppercase and lowercase letters.


Input:
2
abcd xycd
efgh jghi
Output:
6
6
Explanation:
Test Case 1: One of the shortest answer can be abxycd, which is of length 6.

*/