#include <bits/stdc++.h>
using namespace std;

bool iscyclic(int i , bool * visited  , bool * instack , vector<int> adj[]){
    
    if(instack[i] == true){
        return true;
    }
    if(visited[i] == true){
        return false;
    }
    
    visited[i] = true;
    instack[i] = true;
    
    for(auto it = adj[i].begin(); it!= adj[i].end(); it++ ){
        if(iscyclic(*it , visited , instack , adj)){
            return true;
        }
    }
    instack[i] = false;
    
    return false;
}
bool isCyclic(int V, vector<int> adj[])
{
    // Your code here
    
    bool* visited = new bool [V];
    bool* instack = new bool [V];
    
    for(int i=0;i<V;i++){
        visited[i] = false;
        instack[i] = false;
    }
    
    for(int i=0;i<V;i++){
        if(!visited[i]){
         if(iscyclic(i , visited , instack , adj)){
             return true;
         }
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