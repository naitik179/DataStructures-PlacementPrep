#include <bits/stdc++.h>
using namespace std;

bool vis[100][100];
bool exist;
int dx[8] = {-1,-1,0,1,1,1,0,-1};
int dy[8] = {0,1,1,1,0,-1,-1,-1};
void dfs(vector<vector<char> >& board, string word, int i, int x, int y, int n, int r, int c){
    
    if(i<n && x>=0 && x<r && y>=0 && y<c && board[x][y] == word[i]){
        if(i == n-1){
            exist = true;
            return;
        }
        vis[x][y] = true;
        for(int k=0; k<8; k++){
            int x1 = x + dx[k];
            int y1 = y + dy[k];
            
            if(x1>=0 && x1<r && y1>=0 && y1<c && vis[x1][y1] == false)
                dfs(board, word, i+1, x1, y1, n, r, c);
        }
        vis[x][y] = false;
    }
}

bool WordSearch(vector<vector<char> >& board, string word) {
    // Your code goes here
    int n = board.size();
    int m = board[0].size();
    exist = false;
    
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(board[i][j] == word[0]){
                
                for(int x=0;x<n;x++)
                    for(int y=0;y<m;y++)
                        vis[x][y] = false;
                        
                dfs(board, word, 0, i, j, word.size(), n, m);
                if(exist)
                    return true;
            }
        }
    }
    
    return false;
}
vector<string> boggle(vector<vector<char> >& board,
                      vector<string>& dictionary) {
    // Your code goes here
    
    vector<string> ans;
    for(int i=0;i<dictionary.size(); i++){
        if(WordSearch(board, dictionary[i]))
            ans.push_back(dictionary[i]);
    }
    return ans;

}


int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<string> dictionary;
        for (int i = 0; i < n; ++i) {
            string s;
            cin >> s;
            dictionary.push_back(s);
        }
        
        int r, c;
        cin >> r >> c;
        vector<vector<char> > board(r);
        for (int i = 0; i < r; i++) {
            board[i].resize(c);
            for (int j = 0; j < c; j++) cin >> board[i][j];
        }
        vector<string> output = boggle(board, dictionary);
        if (output.size() == 0)
            cout << "-1";
        else {
            sort(output.begin(), output.end());
            for (int i = 0; i < output.size(); i++) cout << output[i] << " ";
        }
        cout << endl;
    }
}
