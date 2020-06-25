#include<bits/stdc++.h>
const int mod=1e9+7;
using namespace std;

int lcs(int, int, string, string);

int main()
{
    int t,n,k,x,y;
    
    cin>>t;
    while(t--)
    {
        cin>>x>>y;          // Take size of both the strings as input
        string s1,s2;
        cin>>s1>>s2;        // Take both the string as input
        
        cout << lcs(x, y, s1, s2) << endl;
    }
    return 0;
}

int lcs(int x, int y, string s1, string s2){
    
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
    
    return dp[n][m];
    
}
