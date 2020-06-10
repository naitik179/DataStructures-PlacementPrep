bool comp(string & a,string & b){
    return a+b>b+a;
}


string Solution::largestNumber(const vector<int> &A) {
    
    vector<string>v;
    
    for(int i=0;i<A.size();i++){
        v.push_back(to_string(A[i]));
    }
    
    sort(v.begin(),v.end(),comp);
    
    string ans="";
    for(int i=0;i<A.size();i++){
        ans.append(v[i]);
    }
    
    return (ans[0]=='0')?"0":ans;
}
