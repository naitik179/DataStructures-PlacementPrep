vector<int> Solution::prevSmaller(vector<int> &A) {
    
    int n=A.size();
stack<int> X;
vector<int> G;
X.push(-1);
G.push_back(X.top());

for(int i=1; i<A.size(); i++) {
    if(A[i]>A[i-1]) {
        X.push(A[i-1]);
    }
    else {
        while(A[i]<=X.top()) {
            X.pop();
        }
        
        X.push(X.top());
    }
    /*else {
        X.push(-1);
    }*/
    G.push_back(X.top());    
}

return G;

}
