class Solution {
public:
    int countSubstrings(string s) {
        int ans=0;
        int n = s.length();
        for(int centre = 0;centre<=2*n-1;centre++){
            int l = centre/2;
            int r= l+ centre%2;
            
            while(l>=0 && r<n && s[l]==s[r]){
                ans++;
                l--;
                r++;
            }
        }
        return ans;
    }
};