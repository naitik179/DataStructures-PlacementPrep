// { Driver Code Starts
// Counts Palindromic Subsequence in a given String
#include<iostream>
#include<cstring>
using namespace std;
 
// Function return the total palindromic subsequence
int countPS(string str);
 
// Driver program
int main()
{
   int t;
	cin>>t;
   while(t--)
	{
	string str;
cin>>str;
cout<<countPS(str)<<endl;
} 
}// } Driver Code Ends


/*You are required to complete below method */
int countPS(string str)
{
    int n = str.length();
    int cps[n+1][n+1];
    memset(cps, 0, sizeof(cps));
    for(int i=0;i<n;i++)cps[i][i]=1;
    for(int L=2;L<=n;L++){
        for(int i=0;i<n;i++){
            int k = i+L-1;
            if(str[i]==str[k])
                cps[i][k] = cps[i+1][k]+cps[i][k-1]+1;
            else
                cps[i][k] = cps[i+1][k]+cps[i][k-1]-cps[i+1][k-1];
        }    
    }
    return cps[0][n-1];
}
 