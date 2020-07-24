TreeNode *buildtree(vector<int>&in , vector<int>&po ,int &postindex ,unordered_map<int , int>&m , int start , int end){
    if(start > end){
        return NULL;
    }
    
    int curr = po[postindex--];
    TreeNode *node = new TreeNode(curr);
    if(start == end){
        return node;
    }
    
    int iindex = m[curr];
    
    node->right = buildtree(in , po , postindex , m , iindex+1 , end);
    node->left = buildtree(in , po , postindex , m , start , iindex -1);
    
    return node;
}
TreeNode* Solution::buildTree(vector<int> &A, vector<int> &B) {
    
    int l = A.size();
    unordered_map<int , int>m;
    
    for(int i=0;i<A.size();i++){
        m[A[i]] = i;
    }
    
    int postindex = B.size()-1;
    return buildtree(A , B , postindex , m , 0 , A.size() - 1);
}