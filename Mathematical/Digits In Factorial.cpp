#include<bits/stdc++.h>
using namespace std;

// This function finds factorial of large numbers 
// and prints them 
//You need to complete this function
int digitsInFactorial(int N)
{
    //Your code here
    double count =0;
    for(int i=1;i<=N;i++)
    {
        count += log10(i);
    }
    
    return floor(count)+1;
}

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int N;
        cin>>N;
        cout<<digitsInFactorial(N)<<endl;
    }
    return 0;
}

/*

when we need to find the number of digits in a mumber say 10000 we say there are 5 digits becauuse it can be represented by 10^4 + 1

similary 

Let's take 10!=10^x to get the value of x.

Take log both sides log(10)!=xlog10

log(10*9*8*..*1)=x

log10+log9+log8+...+log1=x

Take the floor of sum and add 1 to get the number of digits.


*/