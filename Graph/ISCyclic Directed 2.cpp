#include <bits/stdc++.h>
using namespace std;


bool iscyclicutil(vector<int> adj[] , vector<bool>visited , int curr)
{
    if(visited[curr] == true){
        return true;
    }
    int FLAG = false;
    visited[curr] = true;
    
        for(int i=0;i<adj[curr].size();i++){
            FLAG = iscyclicutil(adj , visited , adj[curr][i]);
            if(FLAG == true){
                return true;
            }
        }
    return false;
}
bool iscyclic(int V , vector<int> adj[]){
    
    int FLAG = false;
    
    vector<bool>visited(V , false);
    
    for(int i=0;i<V;i++){
        visited[i] = true;
        for(int j=0;j<adj[i].size();j++){
            FLAG = iscyclicutil(adj , visited , adj[i][j]);
            
            if(FLAG == true){
                return true;
            }
        }
        
        visited[i] = false;
    }
    return false;
}
bool isCyclic(int V, vector<int> adj[])
{
    // Your code here
    return iscyclic(V , adj);
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