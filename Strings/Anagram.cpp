#include <bits/stdc++.h>
using namespace std;

/*  Function to check if two strings are anagram
*   c, d: input string

Given two strings a and b consisting of lowercase characters. The task is to check whether two given strings 
are anagram of each other or not. An anagram of a string is another string that contains same characters,
 only the order of characters can be different. For example, “act” and “tac” are anagram of each other.
*/
bool isAnagram(string c, string d){
   
   
   int a[26] = {0};
   
   for(int i=0;i<c.length();i++){
       a[c[i]-'a']++;
   }
   
   for(int j=0;j<d.length();j++){
       a[d[j]-'a']--;
   }
   
   for(int i=0;i<26;i++){
       if(a[i] != 0){
           return false;
           break;
       }
   }
   
   return true;
}




int main() {
    
    int t;

    cin >> t;

    while(t--){
        string c, d;

        cin >> c >> d;

        if(isAnagram(c, d)) cout << "YES" << endl;
        else cout << "NO" << endl;
    }

}
