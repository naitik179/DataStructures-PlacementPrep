#include<bits/stdc++.h>
using namespace std;


vector <int> nearlySorted(int arr[], int num, int K){
    // Your code here
    
    priority_queue <int, vector<int>, greater<int>> pq;
    
    for(int i=0;i<num;i++){
        pq.push(arr[i]);
    }
    
    vector<int>v;
    for(int i=0;i<num;i++){
        v.push_back(pq.top());
        pq.pop();
    }
    
    return v;
}

int main()
 {
	int T;
	cin>> T;
	
	while (T--)
	{
	    int num, K;
	    cin>>num>>K;
	    
	    int arr[num];
	    for(int i = 0; i<num; ++i){
	        cin>>arr[i];
	    }
	    
	    vector <int> res = nearlySorted(arr, num, K);
	    for (int i = 0; i < res.size (); i++)
	        cout << res[i] << " ";
	        
	    cout<<endl;
	}
	
	return 0;
}
