#include <bits/stdc++.h>
using namespace std;

int maxLen(int A[], int n);

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        int A[N];
        for (int i = 0; i < N; i++) cin >> A[i];
        cout << maxLen(A, N) << endl;
    }
}

int maxLen(int A[], int n) {
    
    unordered_map<int,int>m;
    int sum = 0;
    int len = 0;
    
    for(int i=0;i<n;i++){
        sum += A[i];
        
        if(A[i] == 0 && len == 0){
            len = 1;
        }
        
        if(sum == 0){
            len = i+1;
        }
        
        if(m.find(sum) != m.end()){
            len = max(len , i - m[sum]);
        }
        
        else{
            m[sum] = i;
        }
    }
    
    return len;
}
