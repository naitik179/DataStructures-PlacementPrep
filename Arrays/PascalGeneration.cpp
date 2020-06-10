class Solution {
public:
    vector<vector<int>> generate(int n) {
        
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        vector<vector<int>>v (n);
        
        
        
        if(n == 0){
            return v;
        }
        
        v[0].push_back(1);
        
        for(int i=1;i<n;i++){
            v[i].push_back(1);
            for(int j=1;j<i;j++){
                int x = v[i-1][j-1]+v[i-1][j];
                v[i].push_back(x);
            }
            v[i].push_back(1);
        }
        
        return v;
    }
};