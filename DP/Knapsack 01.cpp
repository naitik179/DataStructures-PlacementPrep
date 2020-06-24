#include<bits/stdc++.h>
using namespace std;

// Returns the maximum value that  
// can be put in a knapsack of capacity W 
int knapSack(int W, int wt[], int val[], int n) 
{ 
   int V[n+1][W+1];
   
   for(int i=0;i<=n;i++){
       for(int w=0;w<=W;w++){
           if(i == 0 || w == 0){
               V[i][w] = 0;
           }
           else if(wt[i-1] <= w){
               V[i][w] = max(V[i-1][w] , (V[i-1][w - wt[i-1]] + val[i-1]));
           }
           else{
               V[i][w] = V[i-1][w];
           }
       }
   }
   
   return V[n][W];
}

int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        int n, w;
        cin>>n>>w;
        int val[n];
        int wt[n];
        
        for(int i=0;i<n;i++)
            cin>>val[i];
        
        for(int i=0;i<n;i++)
            cin>>wt[i];
        
        cout<<knapSack(w, wt, val, n)<<endl;
        
    }
	return 0;
} 