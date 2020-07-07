#include <iostream>
using namespace std;
int remainderWith7(string );

int main() {
int t;
cin>>t;
while(t--)
{
string n;
cin>>n;

cout<<remainderWith7(n)<<endl;

}
	return 0;
}/
int remainderWith7(string n)
{
    int series[] = {1,3,2,-1,-3,-2};
    int index = 0;
    
    int s = n.length();
    int result = 0;
    for(int i=s-1;i>=0;i--){
        int digit = n[i] - '0';
        result += digit*series[index];
        index = (index+1)%6;
        result = result%7;
    }
    
    if(result < 0){
        result = (result + 7)%7;
    }
    
    return result;
}