#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--){
	    int N , M;
	    cin>>N>>M;
	    int flag = 0;
	    vector<vector<int>>A(N, vector<int>(M , 0));
	    vector<vector<int>>visited(N, vector<int>(M , 0));
	    int tgx , tgy;
	    
	    
	    for(int i=0;i<N;i++){
	        for(int j = 0;j<M;j++){
	            cin>>A[i][j];
	        }
	    }
	    
	    cin>>tgx>>tgy;
	    int res = - 1;
	    
	    
	    if(tgx == 0 && tgy == 0 && A[0][0] == 1){
	        res = 0;
	    }
	    else if(A[0][0] == 1 && A[tgx][tgy] ==1){
	        
	        queue<pair<int , int>>q;
	        q.push(make_pair(0 , 0));
	        visited[0][0] = 1;
	        
	        int rr[4] = {-1, 0 , 1 , 0};
	        int cc[4] = { 0, 1 , 0 , -1};
	        
	        while(!q.empty()){
	            int r = q.front().first;
	            int c = q.front().second;
	            q.pop();
	            
	            
	            for(int i=0;i<4;i++){
	                int nextr = r + rr[i];
	                int nextc = c + cc[i];
	                
	                
	                if(nextr < 0 || nextr >=N || nextc <0 || nextc >= M){
	                    continue;
	                }
	                if(visited[nextr][nextc]){
	                    continue;
	                }
	                if(A[nextr][nextc] == 0){
	                    continue;
	                }
	                
	                if(nextr == tgx and nextc == tgy){
	                    if(res == -1){
	                        res = visited[r][c] +1;
	                    }
	                    else{
	                        res = min(res , visited[r][c] +1);
	                    }
	                }
	                
	                visited[nextr][nextc] = visited[r][c] +1;
	                q.push(make_pair(nextr , nextc));
	            }
	        }
	    }
	    if(res == 0 || res == -1){
	        cout<<res<<"\n";
	    }
	    else{
	    cout<<res -1<<"\n";
	    }
	}
	return 0;
}