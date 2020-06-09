vector<int> Solution::flip(string A) 
{
    long long int maxsofar = 0;
    long long int maxendhere = 0;
    int i =0,j =0 ,start=-1,end=-1;
    
    for(i=0;i<A.size();i++){
        maxendhere += (A[i]=='1')?-1:1;
        if(maxsofar < maxendhere){
            maxsofar = maxendhere;
            start = j;
            end  = i;
        }
        if(maxendhere < 0){
            j=i+1;
            maxendhere = 0;
        }
    }
    vector<int>v;
    if(maxsofar){
        v.push_back((start+1));
        v.push_back((end+1));
    }
    return v;
}