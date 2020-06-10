#define ll long long int
vector<int> Solution::maxset(vector<int> &A) {
    
    ll sum =0;
    ll count=0;
    ll prevcount = 0;
    ll realstart=0; ll start = 0;
    ll end = -1;
    ll a= INT_MIN;
    
    for(int i=0;i<A.size();i++){
        
        if(A[i] < 0){
            prevcount = count;
            sum = 0;
            start = i+1;
            count = 0;
        }
        else{
            sum += A[i];
            count++;
            
            if(sum == a){
                if(count > prevcount){
                    realstart = start;
                    end = i;
                    
                }
            }
            
            if(sum > a){
                a = sum;
                realstart = start;
                end = i;
            }
        }
    }
    
    vector<int>v;
    
    if(end == -1){
        return v;
    }
    else{
        
        for(ll i=realstart;i<=end;i++){
            v.push_back(A[i]);
        }
        
        return v;
    }

}
