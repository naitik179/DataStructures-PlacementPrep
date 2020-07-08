vector<int> Solution::maxone(vector<int> &A, int B) {
    
    int n = A.size();
    
    int wl = 0;
    int wr = 0;
    int bestl = 0;
    int windowsize = 0;
    int zerocount = 0;
    
    while(wr < n){
        
        if(zerocount <= B){
            if(A[wr] == 0){
                zerocount++;
            }
            wr++;
        }
        if(zerocount >B){
            if(A[wl] == 0){
                zerocount--;
            }
            wl++;
        }
        
        if((wr - wl) >= windowsize && zerocount <=B)
        {
            windowsize = (wr - wl);
            bestl = wl;
        }
        
    }
    
    vector<int>ans;
    for(int i = 0;i<windowsize;i++){
        ans.push_back(bestl+i);
    }
    return ans;
}
