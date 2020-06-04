#include <bits/stdc++.h>
using namespace std;

int KthLargest(int arr[], int n, int k);

int main() {

    int t;
    cin >> t;

    while (t--) {
        int n, k;
        cin >> n >> k;

        int arr[n];
        for (int i = 0; i < n; i++) cin >> arr[i];

        cout << KthLargest(arr, n, k) << endl;
    }

    return 0;
}// } Driver Code Ends


void heapify(int arr[], int n, int i)
{
    int largest = i; // Initialize largest as root
    int l = 2 * i + 1; // left = 2*i + 1
    int r = 2 * i + 2; // right = 2*i + 2

    if (l < n && arr[l] > arr[largest])
        largest = l;
    if (r < n && arr[r] > arr[largest])
        largest = r;
    if (largest != i) {
        swap(arr[i], arr[largest]);

        heapify(arr, n, largest);
    }
}

int KthLargest(int arr[], int n, int k) {
    // Your code here
    
    for(int i=(n-2)/2;i>=0;i--)
    {
        heapify(arr,n,i);
    }
    
    for(int i=n-1;i>=0;i--)
    {
        swap(arr[0],arr[i]);
        heapify(arr,i,0);
    }
    
    return arr[n-k]; // to get the kth largest element
   
}