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

int longestSubsequence(int n, int a[])
{
   int lis[n];
   lis[0] = 1;
   for(int i=1;i<n;i++){
       lis[i] = 1;
       for(int j=0;j<i;j++)
       {
           if(a[j] < a[i] && lis[i] < lis[j] + 1){
               lis[i] = lis[j]+1;
           }
       }
   }
   
   return *max_element(lis , lis+n);
}
