#include<bits/stdc++.h>
using namespace std;

vector <int> dijkstra(vector<vector<int>> , int ,int );

int printSolution(vector <int> dist, int n)
{
  
   for (int i = 0; i < n; i++)
      printf("%d ", dist[i]);
  
}
int main()
{
    int t;
    int V;
    cin>>t;
    while(t--){
        cin>>V;
        
        vector<vector<int>> g(V);
        
        for(int i = 0;i<V;i++){
            vector<int> temp(V);
            g[i] = temp;
        }
        
        for(int i=0;i<V;i++)
        {
      	    for(int j=0;j<V;j++)
      	    {
      		    cin>>g[i][j];
      	    }
        }
        
        int s;
        cin>>s;
        
        vector <int> res = dijkstra(g, s, V);
        printSolution (res, V);
        cout<<endl;
       }
        return 0;
}


/*  Function to implement Dijkstra
*   g: vector of vectors which represents the graph
*   src: source vertex to start traversing graph with
*   V: number of vertices
*/
vector <int> dijkstra(vector<vector<int>> a, int src, int n)
{
    // Your code here
    vector<int>distance(n , INT_MAX);
	vector<int>visited(n , 0);
	vector<int>p(n , -1);
	int nextnode;
	
	distance[src] = 0;
	visited[src] = 1;
	
	for(int j=0;j<n;j++)
	{
		if(visited[j]!=1 && a[src][j]!=0)
		{
			if((a[src][j]) < distance[j])
			{
				distance[j]=a[src][j];
				p[j]=src;
			}
		}
	}
	int count =0;
	while(count < n-1){
	    
	    int cv;
	    int min = INT_MAX;
	    for(int j=0;j<n;j++){
	        if(visited[j]!= 1 && distance[j] < min){
	            min= distance[j];
	            nextnode = j;
	            cv = min;
	        }
	    }
	    
	    visited[nextnode] = 1;
	    for(int j=0;j<n;j++){
	        if(visited[j] != 1 && a[nextnode][j]!=0){
	            if((a[nextnode][j] + cv) < distance[j]){
	                distance[j] = cv + a[nextnode][j];
	            }
	        }
	    }
	    count++;
	}
	
	
	return distance;
	
	
}