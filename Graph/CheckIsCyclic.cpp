#include <bits/stdc++.h>
using namespace std;

bool iscyclicutil(int v , bool visited[] , bool restack[] ,vector<int> adj[]){
    
    
    if(visited[v] == false){
        visited[v] = true;
        restack[v] = true;
        
        for(auto i = adj[v].begin(); i != adj[v].end(); ++i)
        {
            if ( !visited[*i] && iscyclicutil(*i, visited, restack  , adj) )
                return true;
            else if (restack[*i])
                return true;
        }
    }
    restack[v] = false;  // remove the vertex from recursion stack
    return false;
}
bool isCyclic(int V, vector<int> adj[])
{
    // Your code here
    bool *visited = new bool[V];
    bool *restack = new bool[V];
    
    for(int i=0;i<V;i++){
        visited[i] = false;
        restack[i] = false;
    }
    
    for(int i=0;i<V;i++){
        if(iscyclicutil(i , visited , restack , adj)){
            return true;
        }
    }
    
    return false;
}

int main() {
	
	int t;
	cin >> t;
	
	while(t--){
	    
	    int v, e;
	    cin >> v >> e;
	    
	    vector<int> adj[v];
	    
	    for(int i =0;i<e;i++){
	        int u, v;
	        cin >> u >> v;
	        adj[u].push_back(v);
	    }
	    
	    cout << isCyclic(v, adj) << endl;
	    
	}
	
	return 0;
}