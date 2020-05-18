#include <bits/stdc++.h>
using namespace std;

void convertToRoman(int ) ;

int main() {
	
	int t;
	cin>>t;
	while(t--)
	{
		int N;
		cin>>N;
		
	convertToRoman(N);
	cout<<endl;
		
	}
	return 0;
}




// n :given number that you are require to convert
void convertToRoman(int n) 
{
    int num[] = {1,4,5,9,10,40,50,90,100,400,500,900,1000}; 
    string sym[] = {"I","IV","V","IX","X","XL","L","XC","C","CD","D","CM","M"}; 
    int i=12;     
    while(n>0) 
    { 
      int div = n/num[i]; 
      n = n%num[i]; 
      while(div--) 
      { 
        cout<<sym[i]; 
      } 
      i--; 
    } 
       
}