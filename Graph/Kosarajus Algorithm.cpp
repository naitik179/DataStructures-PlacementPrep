#include<bits/stdc++.h>
using namespace std;

/*  Function to find the number of strongly connected components
*   using Kosaraju's algorithm
*   V: number of vertices
*   adj[]: array of vectors to represent graph
*/

void dfsutil(int i , bool visited[] , vector<int> adj[] , stack<int>&s){
    
    visited[i] = true;
    
    for(auto it = adj[i].begin();it!=adj[i].end();it++){
        if(!visited[*it]){
            dfsutil(*it , visited , adj , s);
        }
    }
    
    s.push(i);
}

void dfs2nd(int i , bool visited[] , vector<int> transpose[] ){
    
    visited[i] = true;
    
    for(auto it = transpose[i].begin();it!=transpose[i].end();it++){
        if(!visited[*it]){
            dfs2nd(*it , visited , transpose);
        }
    }
    
}


int kosaraju(int V, vector<int> adj[])
{
    // Your code here
    
    stack<int>s;
    
    bool* visited = new bool[V];
    for(int i=0;i<V;i++){
        visited[i] = false;
    }
    
    for(int i=0;i<V;i++){
        if(!visited[i]){
            dfsutil(i , visited , adj , s);
        }
    }
    
    // reversing the graph
    
    vector<int> transpose[V];

    for (int v = 0; v < V; v++) 
    { 
        for(auto i = adj[v].begin(); i != adj[v].end(); ++i) 
        { 
            transpose[*i].push_back(v); 
        } 
    } 
    
    
    // for second dfs

    for(int i=0;i<V;i++){
        visited[i] = false;
    }
    
    int count = 0;
    while(!s.empty()){
        
        int g = s.top();
        s.pop();
        if(visited[g] == false){
            dfs2nd(g , visited , transpose);
            count++;
        }
    }
    
    return count;

}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int a, b;
        cin >> a >> b;
        int m, n;
        vector<int> adj[a];
        for (int i = 0; i < b; i++) {
            cin >> m >> n;
            adj[m].push_back(n);
        }
        cout << kosaraju(a, adj) << endl;
    }
    return 0;
}
