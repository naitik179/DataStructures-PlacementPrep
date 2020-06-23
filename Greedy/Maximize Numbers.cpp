/*
		Given two numbers 'N' and 'S' , find the largest number that can be formed with 'N' digits and whose 
		sum of digits should be equals to 'S'.

		Output:
		Print the largest number that is possible.If their is no such number, then print -1 
*/

#include <stdio.h>
#include<bits/stdc++.h>
using namespace std;
int main() {
	int t;
	cin>>t;
	while(t--){
	    int n,s;
	    cin>>n>>s;
	    if(s==0){
	        cout<<"-1"<<"\n";
	    }
	    else{
	    string str="";
	    for(int i=0;i<n;i++){
	        if(s >= 9){
	            str.append("9");
	            s-=9;
	        }
	        else{
	            str.append(to_string(s));
	            s=0;
	        }
	    }
	    if(s==0){
	        cout<<str<<"\n";
	    }
	    else{
	         cout<<"-1"<<"\n";
	    }
	    }
	    
	}
	return 0;
}