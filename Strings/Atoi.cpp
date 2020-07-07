#include <bits/stdc++.h>
using namespace std;

int atoi(string str);
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		cin>>s;
		cout<<atoi(s)<<endl;
	}
}
int atoi(string str)
{

    int minus = 1;
    int i=0;
    int res = 0;
    while(i<str.size()){
        if(str[i] >='a' && str[i]<='z'){
            return -1;
        }
        else if(str[i] == '-'){
            minus = -1;
        }
        else{
            int rr = str[i] - 48;
            res = res*10 + rr;
        }
        i++;
    }
    return (minus*res);
}