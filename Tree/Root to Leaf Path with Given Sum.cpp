void Sum(TreeNode* a, int b,vector<int>v, vector<vector<int>>&ans){
    if(a==NULL )
        return ;
    if(b-(a->val)==0 && a->left==NULL && a->right==NULL){
        v.push_back(a->val);    
        ans.push_back(v);
        return ;
    }
    v.push_back(a->val);
    Sum(a->left,b-(a->val),v,ans);
    Sum(a->right,b-(a->val),v,ans);
}

vector<vector<int>> Solution::pathSum(TreeNode* a, int b) {
    vector<int>v;
    vector<vector<int>>ans;
    Sum(a,b,v,ans);
    return ans;
}