/*

    Given a set of N jobs where each job i has a deadline and profit associated to it.
    Each job takes 1 unit of time to complete and only one job can be scheduled at a time. 
    We earn the profit if and only if the job is completed by its deadline. 
    The task is to find the maximum profit and the number of jobs done.


*/


#include<bits/stdc++.h>
using namespace std; 

struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
}; 



// Prints minimum number of platforms reqquired 

bool comp(struct Job a , struct Job b){
    return a.profit > b.profit;
}
pair<int,int> JobScheduling(Job arr[], int n) 
{ 
    sort(arr , arr +n , comp);
    int jd=0;
    int max = 0;
    int slot[n];
    for(int i=0;i<n;i++){
        slot[i] = false;
    }
    for(int i=0;i<n;i++){
        for(int j=min(n , arr[i].dead) -1 ; j>=0; j--){
            if(slot[j] == false){
                jd++;
                max += arr[i].profit;
                slot[j] = true;
                break;
            }
        }
    }
    
    return {jd , max};
} 

// Driver program to test methods 
int main() 
{ 
    int t;
    cin >> t;
    
    while(t--){
        int n;
        cin >> n;
        Job arr[n];
        
        for(int i = 0;i<n;i++){
                int x, y, z;
                cin >> x >> y >> z;
                arr[i].id = x;
                arr[i].dead = y;
                arr[i].profit = z;
        }
        pair<int,int> ans = JobScheduling(arr, n);
        cout<<ans.first<<" "<<ans.second<<endl;
    }
	return 0; 
}
