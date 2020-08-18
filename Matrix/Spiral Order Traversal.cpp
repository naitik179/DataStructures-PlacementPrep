class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        
         vector<int>v ;
        if(matrix.size()==0) return v;
        
    int dir = 0;
    int top = 0;
    int right = matrix[0].size() -1;
    int bottom = matrix.size() -1;
    int left = 0;
    
       
    
    while(top <= bottom && left <= right){
        if(dir == 0) // move from left to  right
        {
            for(int i=left;i<=right;i++){
                v.push_back(matrix[top][i]);
            }
            top++;
        }
        else if(dir == 1) // from top to bottom
        {
            for(int i=top;i<=bottom;i++){
                v.push_back(matrix[i][right]);
            }
            right--;
        }
        else if(dir == 2)// move from right to left
        {
            for(int i = right;i>=left;i--){
                v.push_back(matrix[bottom][i]);
            }
            bottom--;
        }
        else if(dir == 3)// move from bottm to top
        {
            for(int i=bottom;i>=top;i--){
                v.push_back(matrix[i][left]);
            }
            left++;
        }
        
        dir = (dir+1)%4;
    }
    
    return v;
}
};