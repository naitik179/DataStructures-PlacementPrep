#include<bits/stdc++.h>
using namespace std;
void sort012(int[],int);

int main() {

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >>n;
        int a[n];
        for(int i=0;i<n;i++){
            cin >> a[i];
        }

        sort012(a, n);

        for(int i=0;i<n;i++){
            cout << a[i]  << " ";
        }

        cout << endl;
        
        
    }
    return 0;
}

void sort012(int a[], int n)
{
    // coode here 
    int l = 0;
    int r = n-1;
    int mid = 0;
    
    while(mid <= r){

        if(a[mid] == 0){
            swap(a[l] , a[mid]);
            l++;
            mid++;
        }
        else if(a[mid] == 2){
            swap(a[mid] , a[r]);
            r--;
            // we dont increment mid for the 2 case 
        }
        else{
            mid++;
        }
    }
    
}