#include<bits/stdc++.h>
using namespace std;
// Function to calculate span
// price[]: price array in input
// n: size of array
void calculateSpan(int price[], int n, int S[])
{
   
   
   stack<int>s;
   S[0] =1;
   s.push(0);
   
   for(int i=1;i<n;i++){
       while(!s.empty()  && price[s.top()] <= price[i]){
           s.pop();
       }
       
       if(s.empty()){
           S[i] = i+1;
       }
       else{
           S[i] = i - s.top();
       }
       
       s.push(i);
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
		int i,a[n],s[n];
		for(i=0;i<n;i++)
		{
			cin>>a[i];
		}
		
		calculateSpan(a, n, s);
		
		for(i=0;i<n;i++)
		{
			cout<<s[i]<<" ";
		}
		cout<<endl;
	}
	return 0;
}
