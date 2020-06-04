#include <bits/stdc++.h> 
using namespace std; 


bool comp(const pair<int , int>p1 , const pair<int , int>p2){
    return p1.second > p2.second;
}


// Function to print the k numbers with most occurrences 
int print_N_mostFrequentNumber(int arr[] ,int n, int k) 
{ 
	// Your code here	 
	unordered_map<int ,int>um;
	for(int i=0;i<n;i++){
	    um[arr[i]]++;
	}
	
	vector<pair<int , int>>v;
	for(auto it=um.begin();it!=um.end();it++){
	    v.push_back(make_pair(it->first , it->second));
	}
	
	sort(v.begin() , v.end() , comp);
	
	int sum =0;
	
	for(int i=0;i<k;i++){
	    sum += v[i].second;
	}
	
	return sum;
} 


int main() 
{
	int t;
    cin >> t;

    while(t--){
        int n, k;
        cin >> n;
        int arr[n];
        for(int i = 0;i<n;i++){
            cin >> arr[i];
        }
        cin >> k;
        cout << print_N_mostFrequentNumber(arr, n, k) << endl; 
    }

	return 0; 
} 