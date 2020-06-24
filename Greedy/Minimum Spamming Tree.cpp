#include <bits/stdc++.h>
using namespace std;
int spanningTree(int V, int E, vector<vector<int>> &graph);


int main() {
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int> > graph(V, vector<int>(V, INT_MAX));
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            u--, v--;
            graph[u][v] = w;
            graph[v][u] = w;
        }

        cout << spanningTree(V, E, graph) << endl;
    }
    return 0;
}


// Function to construct and print MST for
// a graph represented using adjacency
// matrix representation, with V vertices.
// graph[i][j] = weight if edge exits else INT_MAX
int spanningTree(int V, int E, vector<vector<int>> &a) {
    
    vector<int>distance(V , INT_MAX);
	vector<int>visited(V , 0);
	vector<int>p(V , -1);
	int nextnode;
	
	distance[0] = 0;
	visited[0] = 1;
	
	for(int j=0;j<V;j++)
	{
		if(visited[j]!=1 && a[0][j]!=INT_MAX)
		{
			if((a[0][j]) < distance[j])
			{
				distance[j]=a[0][j];
				p[j]=0;
			}
		}
	}
	int count =0;
	while(count < V-1){
	    
	    int min = INT_MAX;
	    for(int j=0;j<V;j++){
	        if(visited[j]!= 1 && distance[j] < min){
	            min= distance[j];
	            nextnode = j;
	        }
	    }
	    
	    visited[nextnode] = 1;
	    for(int j=0;j<V;j++){
	        if(visited[j] != 1 && a[nextnode][j]!=0){
	            if(a[nextnode][j] < distance[j]){
	                distance[j] = a[nextnode][j];
	            }
	        }
	    }
	    count++;
	}
	
	int result=0;
	for(int i=0;i<V;i++){
	 result += distance[i];   
	}
	
	return result;
}