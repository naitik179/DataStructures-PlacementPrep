#include <bits/stdc++.h>
using namespace std;

int SubsequenceLength(string s);

int SubsequenceLength (string s) 
{
    // Your code goes here
    
        vector<int> dict(256, -1);
        int maxLen = 0, start = -1;
        for (int i = 0; i != s.length(); i++) {
            if (dict[s[i]] > start)
                start = dict[s[i]];
            dict[s[i]] = i;
            maxLen = max(maxLen, i - start);
        }
        return maxLen;
}

int main()
{
    int t;
    cin>>t;
    cin>>ws;
    while(t--)
    {
        string str;
        getline(cin,str);
        cout<<SubsequenceLength(str)<<"\n";
    }
    return 0;
}