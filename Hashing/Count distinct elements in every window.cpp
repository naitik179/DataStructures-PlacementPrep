
#include <bits/stdc++.h>
using namespace std;

vector <int> countDistinct(int[], int, int);
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        int a[n];
        for (int i = 0; i < n; i++) cin >> a[i];
        vector <int> res = countDistinct(a, n, k);
        for (int i : res) cout << i << " ";
        cout << endl;
    }
    return 0;
}

vector <int> countDistinct(int arr[], int N, int k) {
    
    map<int, int> hm; 
    int dist_count = 0; 
    
    vector<int>v;
    for (int i = 0; i < k; i++) 
    { 
       if (hm[arr[i]] == 0) 
       { 
           dist_count++; 
       } 
        hm[arr[i]] += 1; 
    } 
    v.push_back(dist_count);
  
   for (int i = k; i < N; i++) 
   { 
   
     if (hm[arr[i-k]] == 1) 
     { 
        dist_count--; 
     } 

     hm[arr[i-k]] -= 1; 

    if (hm[arr[i]] == 0) 
    { 
       dist_count++; 
    } 
    hm[arr[i]] += 1; 
  
    v.push_back(dist_count);
  } 
    return v;
}