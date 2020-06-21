#include <bits/stdc++.h>
using namespace std;

int rotOranges(vector<vector<int> > &matrix, int R, int C)
{
    // Your code goes here
    
    const int dx[4] = {-1 , 0  , 1 , 0};
    const int dy[4] = {0 , 1 , 0 , -1 };
    
    
    int total=0;
    int days=0;
    int count=0;
    
    queue<pair<int , int>>q;
    
    for(int i=0;i<R;i++){
        for(int j=0;j<C;j++){
            if(matrix[i][j] != 0){
                total++;
            }
            if(matrix[i][j] == 2){
                q.push({i , j});
            }
        }
    }
    
    while(!q.empty()){
        int k = q.size();
        count += k;
        
        
        while(k--){
        
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        
        for(int i=0;i<4;i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if(nx < 0 || nx >= R || ny < 0 || ny >= C || matrix[nx][ny] !=1){
                continue;
            }
            matrix[nx][ny] = 2;
            q.push({nx , ny});
        }
        }
        
        if(!q.empty()){
            days++;
        }
    }
    
    return (count == total ? days : -1);
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int R,C;
        cin>>R>>C;
        vector<vector<int> > matrix(R);
        for(int i=0;i<R;++i)
        {
            matrix[i].resize(C);
            for(int j=0;j<C;++j)
                cin>>matrix[i][j];
        }
        cout<<rotOranges(matrix,R,C)<<endl;
    }
    return 0;
} 

// time Complexity O(N)