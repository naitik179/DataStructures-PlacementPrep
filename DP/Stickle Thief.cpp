
/*

    Stickler the thief wants to loot money from a society having n houses in a single line.
     He is a weird person and follows a certain rule when looting the houses. According to the rule, 
     he will never loot two consecutive houses. At the same time, he wants to maximize the amount he loots.
    The thief knows which house has what amount of money but is unable to come up with an optimal looting strategy. 
    He asks for your help to find the maximum money he can get if he strictly follows the rule. Each house has a[i] 
    amount of money present in it.



    Input:
    2
    6
    5 5 10 100 10 5
    3
    1 2 3
    Output:
    110
    4

*/

#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;


 // } Driver Code Ends


// Function to return maximum of sum without adjacent elements
ll FindMaxSum(ll arr[], ll n)
{
    if(n == 0){
        return 0;
    }
    else if(n == 1){
        return arr[0];
    }
    else if(n == 2){
        return max(arr[0] , arr[1]);
    }
    ll dp[n];
    dp[0] = arr[0];
    dp[1] = max(arr[0] , arr[1]);
    
    for(ll j=2;j<n;j++){
        dp[(int)j] = max(arr[(int)j] + dp[(int)j-2] , dp[(int)j-1]);
        
    }
    return dp[n-1];
}


// { Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		ll n;
		cin>>n;
		ll a[n];
		for(ll i=0;i<n;++i)
			cin>>a[i];
		cout<<FindMaxSum(a,n)<<endl;
	}
	return 0;
}
