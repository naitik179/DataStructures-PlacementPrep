#include <bits/stdc++.h>
using namespace std;

vector <int> bfs(vector<int> g[], int N);

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, E;
        cin >> N >> E;
        vector<int> adj[N];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }
        vector <int> res = bfs(adj, N);
        for (int i = 0; i < res.size (); i++) cout << res[i] << " ";
        cout << endl;
    }
}// } Driver Code Ends



vector <int> bfs(vector<int> adj[], int N) {

    // Your code here
    vector<int>ans;
    
    int s = 0;
    
    queue<int>q;
    
    bool visited[N];
    for(int i=0;i<N;i++){
        visited[i] = false;
    }
    visited[s] = true;
    q.push(s);
    
    
    while(!q.empty()){
        
        int f = q.front();
        q.pop();
        ans.push_back(f);
        
        for(int i=0;i<adj[f].size();i++)
        {
            if(visited[adj[f][i]] == false){
                
                visited[adj[f][i]] = true;
                q.push(adj[f][i]);
            }
        }
    }
    
    return ans;
    
}