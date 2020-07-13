#include<bits/stdc++.h>
using namespace std;

int maxDistance(int arr[], int n);

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int arr[n];
        for(int i=0; i<n; i++)
            cin>>arr[i];
        cout<<maxDistance(arr,n)<<endl;
    }
    return 0;
}
int maxDistance(int arr[], int n)
{
   unordered_map<int  , int>um;
   
   for(int i=0;i<n;i++){
       um[arr[i]]++;
   }
   int maxd = INT_MIN;
   for(auto it=um.begin();it!=um.end();it++){
       if(it->second > 0){
           int i,j;
           for(i=0;i<n;i++){
               if(arr[i]==it->first){
                   break;
               }
           }
           for(j=n-1;j>=0;j--){
               if(arr[j]==it->first){
                   break;
               }
           }
           maxd = max(maxd , (j-i));
       }
   }
   
   return maxd;
   
   
}