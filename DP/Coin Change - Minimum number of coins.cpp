#include <bits/stdc++.h>
using namespace std;

long long minimumNumberOfCoins(int coins[],int numberOfCoins,int value)
{
    // your code here
    vector<long long> dp(value+1, INT_MAX);
    dp[0] = 0;
    for (int i = 1; i <= value; i++) {
        for (int j = 0; j < numberOfCoins ; j++) {
            if (i >= coins[j] ) dp[i] = min(dp[i], dp[i - coins[j]] + 1);
        }
    }
    return dp[value] == INT_MAX ? -1 : dp[value];
}

int main() {
	int testcases;
	cin>>testcases;
	while(testcases--)
	{
	    int value;
	    cin>>value;
	    int numberOfCoins;
	    cin>>numberOfCoins;
	    int coins[numberOfCoins];
	    
	    for(int i=0;i<numberOfCoins;i++)
	    cin>>coins[i];
	    
	    int answer=minimumNumberOfCoins(coins,numberOfCoins,value);
	    if(answer==-1)
	    cout<<"Not Possible"<<endl;
	    else
	    cout<<answer<<endl;
	    
	}
	return 0;
}