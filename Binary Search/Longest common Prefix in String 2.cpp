string find(string ans, string s){
        string res;
        int n=ans.size();
        int m=s.size();
        for(int i=0;i<min(n,m);i++)
        {
            if(ans[i]!=s[i])
            break;
        res.push_back(ans[i]);
        }
        return res;
}

string Solution::longestCommonPrefix(vector<string> &A) {
        string ans=A[0];
        for(int i=1;i<A.size();i++)
        {
        ans= find(ans,A[i]);
        }
        return ans;
}
