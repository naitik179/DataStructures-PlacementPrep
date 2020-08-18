vector<vector<int> > Solution::generateMatrix(int A) {
    
    int dir = 0;
    int top = 0;
    int right = A-1;
    int bottom = A-1;
    int left = 0;
    int k =1;
    
    vector<vector<int>>v (A,vector<int>(A,0));// ans 
    
    while(top <= bottom && left <= right){
        if(dir == 0) // move from left to  right
        {
            for(int i=left;i<=right;i++){
                v[top][i] = k;
                k++;
            }
            top++;
        }
        else if(dir == 1) // from top to bottom
        {
            for(int i=top;i<=bottom;i++){
                v[i][right] = k;
                k++;
            }
            right--;
        }
        else if(dir == 2)// move from right to left
        {
            for(int i = right;i>=left;i--){
                v[bottom][i] = k;
                k++;
            }
            bottom--;
        }
        else if(dir == 3)// move from bottm to top
        {
            for(int i=bottom;i>=top;i--){
                v[i][left] = k;
                k++;
            }
            left++;
        }
        
        dir = (dir+1)%4;
    }
    
    return v;
}
