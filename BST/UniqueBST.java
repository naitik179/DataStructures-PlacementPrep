import java.util.*;
import java.io.*;
import java.lang.*;

//User function Template for Java

class Solution
{
    // Return the total number of BSTs possible with keys [1....N] inclusive.
    static int numTrees(int n)
    {
        // Your code goes here
         long []dp = new long [n+1];
         dp[0] = 1;
         dp[1] = 1;
         long mod = 1000000007;
    
        for(int i=2;i<=n;i++){
            for(int j=1;j<=i;j++){
                dp[i] = (dp[i] +  dp[j-1]*dp[i-j])%mod;
            }
        }
    
        return (int)dp[n];
        
    }
}

class GFG
{
    public static void main(String args[])
    {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        
        while(t-- > 0)
        {
            int n =sc.nextInt();
            Solution T = new Solution();
            System.out.println(T.numTrees(n));
        }
    }
}
 

/*


		CATALAN NUMBER 

		for(int i=2;i<=n;i++){
            c[i] = 0;
            for(int j=0;j<i;j++){
                c[i] += c[j]*c[i-j-1];
            }
        }




*/