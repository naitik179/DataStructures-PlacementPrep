#include <bits/stdc++.h>
using namespace std;

#define SIZE 100

/*  Function to find the area of 1s
*   SIZE: declared globally for matrix definition
*   n, m: row and column of matrix
*   A[][]: 2D matrix from input
*/


int issafe(int i , int j , vector<vector<bool>>&visited , int A[SIZE][SIZE] , int N , int M)
{
    return ((i >=0) && (i<N) && (j>=0) && (j<M) && (visited[i][j] == false) && (A[i][j] == 1));
}
void dfs(int i , int j , vector<vector<bool>>&visited , int A[SIZE][SIZE] , int N , int M ,int &count){
    
    
    int row[] = {-1, -1, -1, 0,
                 0,  1,  1,  1}; // Check for all 8 neighbours of i and j
    int col[] = {-1, 0, 1, -1, 1, -1, 0, 1};
    visited[i][j] = true;
        for(int r =0 ;r<8;r++){
            if(issafe(i + row[r] , j + col[r] , visited , A , N , M)){
                count++;
                dfs(i+row[r], j+col[r] , visited , A , N ,M , count);
            }
        }
}

int findMaxArea(int N, int M, int A[SIZE][SIZE] )
{

    vector<vector<bool>>visited(N , vector<bool>(M , false));
    int result = INT_MIN;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            if(!visited[i][j] && A[i][j]){
                int count = 1;
                dfs(i , j , visited , A , N , M, count);
                result = max(result , count);
            }
            
        }
    }
    
    return result;
    
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;

        int g[SIZE][SIZE];

        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                cin >> g[i][j];

        cout << findMaxArea(n, m, g) << endl;
    }

    return 0;
} 