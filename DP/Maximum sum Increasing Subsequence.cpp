#include<bits/stdc++.h>
using namespace std;

int longestSubsequence(int, int[]);

int main()
{
    int t,n;
    cin>>t;
    while(t--)
    {
        cin>>n;
        int a[n];
        for(int i=0;i<n;i++)
            cin>>a[i];

        cout << longestSubsequence(n, a) << endl;
    }
}

// Variant of Longest Increasing Subsequence
int longestSubsequence(int n, int a[])
{
   int lis[n];
   for(int i=0;i<n;i++){
       lis[i] = a[i];
       for(int j=0;j<i;j++)
       {
           if(a[j] < a[i]){
               lis[i] = max(lis[j]+a[i] , lis[i]);
           }
       }
   }
   
   return *max_element(lis , lis+n);
}
