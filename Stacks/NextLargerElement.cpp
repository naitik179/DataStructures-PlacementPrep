
#include<bits/stdc++.h>
using namespace std;

void nextLargerElement(long long arr[], int n){
    // Your code here
    
   stack<long long>s;
   long long arr1[n];
   
   for(int i= n-1;i>=0;i--){
       
       while(!s.empty() && s.top() <= arr[i]){
           s.pop();
       }
       
       if(s.empty()){
           arr1[i] = -1;
       }
       
       else {
           arr1[i] = s.top();
       }
       
       s.push(arr[i]);
   }
   
   for(int i=0;i<n;i++){
       cout<<arr1[i]<<" ";
   }
    
}



int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        
        int n;
        cin>>n;
        long long arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        
        
        nextLargerElement(arr, n);
        
        cout<<endl;
    }
  return 0;
}
