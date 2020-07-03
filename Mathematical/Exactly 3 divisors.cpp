// { Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


//User function Template for C++

//You need to complete this function
bool isPrime(int N)
{
    int dp[N+1] = {0};
    
    dp[1] = 1;
    
    for(int p = 2; p*p<=N+1; p++){
        
        if(dp[p] == 0){
            
            for(int c = p*p ; c<=N+1;c+=p){
                dp[c] =1;
            }
        }
        
    }
    
    if(dp[N] == 0)
    {
        return true;
    }
    else{
        return false;
    }
}


// { Driver Code Starts.

int main()
{
    int T; //testcases
    cin>>T; //input testcases
    while(T--) //while testcase have not been exhausted
    {
        int N;
        cin>>N; //input n
        
        if(isPrime(N)) 
        cout<<"Yes";
        else
            cout<<"No";
            
        cout << endl;
    }
    return 0;
}
  // } Driver Code Ends