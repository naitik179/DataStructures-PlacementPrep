#include <bits/stdc++.h>
using namespace std;

vector <int> topoSort(int N, vector<int> adj[]);

/*  Function to check if elements returned by user
*   contains the elements in topological sorted form
*   V: number of vertices
*   *res: array containing elements in topological sorted form
*   adj[]: graph input
*/
bool check(int V, vector <int> &res, vector<int> adj[]) {
    vector<int> map(V, -1);
    for (int i = 0; i < V; i++) {
        map[res[i]] = i;
    }
    for (int i = 0; i < V; i++) {
        for (int v : adj[i]) {
            if (map[i] > map[v]) return false;
        }
    }
    return true;
}

// Driver Code
int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, E;
        cin >> E >> N;
        int u, v;

        vector<int> adj[N];

        for (int i = 0; i < E; i++) {
            cin >> u >> v;
            adj[u].push_back(v);
        }

        vector <int> res = topoSort(N, adj);

        cout << check(N, res, adj) << endl;
    }
}// } Driver Code Ends


void toposortutil(int i , vector<int> adj[] , bool visited[] , stack<int>&s){
    
    visited[i] = true;
    
    for(auto it = adj[i].begin();it!=adj[i].end();it++){
        if(!visited[*it]){
            toposortutil( *it , adj , visited , s);
        }
    }
    
    s.push(i);
}
vector<int> topoSort(int V, vector<int> adj[]) {
    // Your code here
    
    bool* visited = new bool[V];
    stack<int>s;
    for(int i=0;i<V;i++){
        visited[i] = false;
    }
    
    vector<int>ans;
    for(int i=0;i<V;i++){
        if(visited[i] == false){
            toposortutil( i , adj , visited , s);
        }
    }
    
    while(!s.empty()){
        ans.push_back(s.top());
        s.pop();
    }
    
    return ans;
}
