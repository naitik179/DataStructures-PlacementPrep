#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define pf push_front

ll mat[1001][1001];
bool vis[1001][1001];

ll bfs(ll n, ll m, ll i, ll j){
    vis[i][j] = true;
    queue<pair<ll, ll>> q;
    q.push(make_pair(i, j));
    
    ll dx[] = {-1, -1, -1, 1, 1, 1, 0, 0};
    ll dy[] = {-1, 0, 1, -1, 0, 1, -1, 1};
    ll cnt = 0;
    while(!q.empty()){
        ll len = q.size();
        while(len--){
            pair<ll, ll> p = q.front();
            cnt++;
            q.pop();
            
            for(ll k=0; k<8; k++){
                ll x = p.first + dx[k], y = p.second + dy[k];
                if(x>=0 && x<n && y>=0 && y<m && mat[x][y] && !vis[x][y]){
                    vis[x][y] = true;
                    q.push(make_pair(x, y));
                }
            }
        }
    }
    return cnt;
}

ll largestRegion(ll n, ll m){
    memset(vis, false, sizeof(vis));
    ll max_area = 0;
    for(ll i=0; i<n; i++){
        for(ll j=0; j<m; j++){
            if(mat[i][j] && !vis[i][j]){
                max_area = max(max_area, bfs(n, m, i, j));
            }
        }
    }
    return max_area;
}

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll t;
    cin>>t;
    while(t--)
    {
        ll n,m; cin>>n>>m;
        for(ll i=0; i<n; i++){
            for(ll j=0; j<m; j++){
                cin>>mat[i][j];
            }
        }
        
        cout<<largestRegion(n, m)<<"\n";
    }
    return 0;
}