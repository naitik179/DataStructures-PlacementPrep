// { Driver Code Starts
// C++ program to check if two strings are isomorphic
#include<iostream>
#include<string.h>

using namespace std;
#define MAX_CHARS 256

bool areIsomorphic(string, string);

// Driver program
int main()
{
    int t;
    cin>>t;
    string s1,s2;
    while (t--) {
        cin>>s1;
        cin>>s2;
        cout<<areIsomorphic(s1,s2)<<endl;
    }
    
    return 0;
}// } Driver Code Ends


// This function returns true if str1 and str2 are ismorphic
// else returns false
bool areIsomorphic(string str1, string str2)
{
    
    // Your code here
    int m1[MAX_CHARS] = {0};
    int m2[MAX_CHARS] = {0};
    
    int n = str1.size();
    int m = str2.size();
    
    if(n != m){
        return false;
    }
    else{
        
        for(int i=0;i<n;i++){
            if(m1[str1[i]] != m2[str2[i]]){
                return false;
            }
            
            m1[str1[i]] = i+1;
            m2[str2[i]] = i+1;
        }
    }
    
    return true;
    
}