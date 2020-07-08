#include<bits/stdc++.h>
using namespace std;

int countSetBits(int n)
{

    int a[32];
    int ans =0;
    int one=0;
    for(int i=0;i<32;i++){
        if(n>>i & 1){
            a[i] = 1;
            one++;
        }
        else{
            a[i] = 0;
        }
    }
    ans += one;
    
    for(int i=0;i<32;i++){
        
        if(a[i] == 1){
            one--;
            if(i == 0){
                ans += one;
            }
            else{
                ans += pow(2 , i)*one + pow(2,i-1)*i;
            }
        }
    }
    
    return ans;
}

int main()
{
	 int t;
	 cin>>t;// input testcases
	 while(t--) //while testcases exist
	 {
	       int n;
	       cin>>n; //input n
	       
	       cout << countSetBits(n) << endl;// print the answer
	  }
	  return 0;
}
