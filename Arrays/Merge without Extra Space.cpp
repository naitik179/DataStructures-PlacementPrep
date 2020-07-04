#include <bits/stdc++.h> 
using namespace std; 

// Function to merge two input arrays
// arr1[], arr2[]: input arrays
// n, m: size of arr1[] and arr2[] respectively
void merge(int a1[], int a2[], int n, int m) 
{ 
    
    int x = n-1;
    int y = 0;
    
    while(x >= 0 && y<m){
        if(a1[x] > a2[y]){
            swap(a1[x] , a2[y]);
            x--;
            y++;
        }
        else{
            x--;
        }
    }
    
    sort(a1 , a1+n);
    sort(a2 , a2 + m);
    
} 

int main() 
{ 
    
    int T;
    cin >> T;
    
    while(T--){
        int n, m;
        cin >> n >> m;
        
        int arr1[n], arr2[m];
        
        for(int i = 0;i<n;i++){
            cin >> arr1[i];
        }
        
        for(int i = 0;i<m;i++){
            cin >> arr2[i];
        }
        
        merge(arr1, arr2, n, m); 

        for (int i = 0; i < n; i++) 
            printf("%d ", arr1[i]); 
        
       
        for (int i = 0; i < m; i++) 
            printf("%d ", arr2[i]); 
        
        cout<<endl;
    }

    return 0; 
} 