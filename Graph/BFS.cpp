// { Driver Code Starts
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


/* You have to complete this function*/

/* Function to do BFS of graph
*  g[]: adj list of the graph
*  N : number of vertices
*/
vector <int> bfs(vector<int> g[], int N) {

    // Your code here
    vector <bool> vis (N, false);
    int s = 0;
    vis[s] = true; // Initially mark source vertex as visited(true)
    vector <int> res;
    queue<int> q;
    q.push(s); // Push the source vertex to queue

    while (!q.empty()) // Till queue is not empty
    {
        int t = q.front();
        res.push_back (t);

        q.pop(); // Pop the queue front

        for (int v :
             g[t]) // Traverse through all the connected components of front
        {
            if (!vis[v]) { // If they are not visited, mark them visited and add
                           // to queue
                vis[v] = true;
                q.push(v);
            }
        }
    }
    return res;
   
}