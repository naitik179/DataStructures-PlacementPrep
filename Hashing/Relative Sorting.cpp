//Initial template for C++

#include <bits/stdc++.h> 
using namespace std;



void sortA1ByA2(int a1[], int n, int a2[], int m);

// Driver program to test above function 
int main(int argc, char *argv[]) 
{ 
	
	int t;
	
	cin >> t;
	
	while(t--){
	    
	    int n, m;
	    cin >> n >> m;
	    
	    int a1[n];
	    int a2[m];
	    
	    for(int i = 0;i<n;i++){
	        cin >> a1[i];
	    }
	    
	    for(int i = 0;i<m;i++){
	        cin >> a2[i];
	    }
	    
	    sortA1ByA2(a1, n, a2, m); 
	
	   
	    for (int i = 0; i < n; i++) 
		    cout<<a1[i]<<" ";
		
	    cout << endl;
	    
	    
	}
	return 0; 
} 
// } Driver Code Ends


//User function template in C++

// A1[] : the input array-1
// N : size of the array A1[]
// A2[] : the input array-2
// M : size of the array A2[]
void sortA1ByA2(int A1[], int N, int A2[], int M) 
{
    //Your code here
    map<int , int>m;
    
    for(int i=0;i<N;i++){
        m[A1[i]]++;
    }
    
    set<int>s;
    int k=0;
    for(int i=0;i<M;i++){
        auto it = m.find(A2[i]);
        if(it != m.end()){
            s.insert(it->first);
            for(int j = 0;j<it->second;j++){
                // cout<<it->first<<" ";
                A1[k] = it->first;
                k++;
            }
        }
    }
    
    for(auto it2 = m.begin();it2!=m.end();it2++){
        if(s.find(it2->first)  == s.end()){
            for(int h = 0;h<it2->second;h++){
                // cout<<it2->first<<" ";
                A1[k] = it2->first;
                k++;
            }
        }
        else{
            continue;
        }
    }
} 