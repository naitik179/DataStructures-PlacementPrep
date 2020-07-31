class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.length();
        vector<bool> dp(s.size()+1,false);
        dp[0]=true;
        for(int len = 1 ; len <=n ; len++){
            dp[len] = false;
            for(int i = 0 ; i < len ; i++){
                string dd = s.substr(i , len);
                auto it = wordDict.find(wordDict.begin() , wordDict.end() ,  dd );
                if(it!= wordDict.end()){
                    if(dp[i]){
                        dp[i] = true;
                        break;
                    }
                }
            }
        }
        
        return dp[n];
    }
};