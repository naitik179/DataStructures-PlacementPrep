#include <iostream>
using namespace std;

int main() {
    int t;
    cin>>t;
    while(t--){
        int n , m;
        cin>>n>>m;
        string s1 ,s2;
        cin>>s1>>s2;
        
        int dp[n+1][m+1];
        int mx=0;
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
                    dp[i][j] = 0;
                }
                mx = max(dp[i][j] , mx);
            }
        }
        
         cout<<mx<<"\n";
        }
}

/*

Note that Longest commom Longest Common substring is different than Longest Common subsequence

ex : String 1 abcdaf
     String 2 zbcdf
               ---
     Ans for Longest Common Substring is 3 ( bcd ) ans is 3
     Ans for Longest common Subsequence is 4 ( bcdf ) ans is 4

*/