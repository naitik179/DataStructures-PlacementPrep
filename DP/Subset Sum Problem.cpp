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
    
    bool subset[n + 1][sum + 1]; 
  
    // If sum is 0, then answer is true 
    for (int i = 0; i <= n; i++) 
        subset[i][0] = true; 
  
    // If sum is not 0 and set is empty, 
    // then answer is false 
    for (int i = 1; i <= sum; i++) 
        subset[0][i] = false; 
  
    // Fill the subset table in botton up manner 
    for (int i = 1; i <= n; i++) { 
        for (int j = 1; j <= sum; j++) { 
            if (j < a[i - 1]) 
                subset[i][j] = subset[i - 1][j]; 
            if (j >= a[i - 1]) 
                subset[i][j] = subset[i - 1][j] 
                               || subset[i - 1][j - set[i - 1]]; 
        } 
    } 
    return subset[n][sum]; 
}