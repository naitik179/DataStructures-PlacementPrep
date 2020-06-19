vector <int> dijkstra(vector<vector<int>> g, int src, int v)
{
    vector<int>ans(v,INT_MAX);
     
     priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>pq;
     
     ans[src]=0;
     pq.push({ans[src],src});
     
       while(pq.size())
      {
          int pick = pq.top().second;
           pq.pop();
           
            for(int i=0;i<v;i++)
            {
                if(g[pick][i] && ans[i]!=100005 && ans[i]>ans[pick]+g[pick][i])
                {
                    ans[i]=ans[pick]+g[pick][i];
                    
                     pq.push({ans[i], i});
                }
            }
      }
      
      return ans;
}