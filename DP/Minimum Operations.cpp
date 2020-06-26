/*


You are given a number N. You have to find the number of operations required to reach N from 0. 
You have 2 operations available:

Double the number
Add one to the number


*/


#include <iostream>
using namespace std;

int main() {
	//code
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    int count=0;
	    while(n){
	        if(n%2 ==0){
	            n=n/2;
	            count++;
	        }
	        else{
	            n = n-1;
	            count++;
	        }
	    }
	    
	    cout<<count<<"\n";
	}
}