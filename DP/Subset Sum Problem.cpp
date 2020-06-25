/*

Given a set of numbers, check whether it can be partitioned into two subsets such that 
the sum of elements in both subsets is same or not.

*/
#include <bits/stdc++.h>

using namespace std;

bool findPartition(int *, int);

int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, i;
        cin >> n;
        int a[n];
        for (i = 0; i < n; i++) cin >> a[i];

        if (findPartition(a, n))
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}


// a : given array
// n : size of the array

bool findPartition(int a[], int n) {
    // code here
    
    int sum=0;
    for(int i=0;i<n;i++){
        sum+=a[i];
    }
    
    bool dp[(sum/2) +1][n+1];
    
    if(sum %2 !=0){
        return false;
    }
    
    for(int i=0;i<=n;i++){
        dp[0][i] = true;
    }
    
    for(int i=1;i<=sum/2;i++){
        dp[i][0] = false;
    }
    
    for(int i=1;i<=sum/2;i++){
        for(int j=1;j<=n;j++){
            if(i >= a[j-1]){
                dp[i][j] = (dp[i - a[j-1]][j-1] || dp[i][j-1]);
            }
            else{
                dp[i][j] = dp[i][j-1];
            }
        }
    }
    
    return dp[sum/2][n];
}