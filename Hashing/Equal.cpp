vector<int> Solution::equal(vector<int> &A) {
    
    int n = A.size();
    unordered_map<int , vector<pair<int , int>>>m;
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            m[A[i]+A[j]].push_back(make_pair(i , j));
        }
    }
    vector<int>ans(4 , INT_MAX);
    for(auto i : m){
        if(i.second.size() >= 2){
            for(int j=0;j<i.second.size();j++){
                auto p1 = i.second[0];
                auto p2 = i.second[j];
                
                if(p1.first < p1.second && p2.first < p2.second && p1.first < p2.first && p1.second != p2.second && p1.second != p2.first){
                    vector<int>temp = {p1.first , p1.second , p2.first , p2.second};
                    
                    if(temp < ans){
                        ans = temp;
                    }
                }
            }
        }
    }
    
    return ans;
}


/*


Given an array A of integers, find the index of values that satisfy A + B = C + D, where A,B,C & D are integers values in the array

Note:

1) Return the indices `A1 B1 C1 D1`, so that 
  A[A1] + A[B1] = A[C1] + A[D1]
  A1 < B1, C1 < D1
  A1 < C1, B1 != D1, B1 != C1 

2) If there are more than one solutions, 
   then return the tuple of values which are lexicographical smallest. 

Assume we have two solutions
S1 : A1 B1 C1 D1 ( these are values of indices int the array )  
S2 : A2 B2 C2 D2

S1 is lexicographically smaller than S2 iff
  A1 < A2 OR
  A1 = A2 AND B1 < B2 OR
  A1 = A2 AND B1 = B2 AND C1 < C2 OR 
  A1 = A2 AND B1 = B2 AND C1 = C2 AND D1 < D2
Example:

Input: [3, 4, 7, 1, 2, 9, 8]
Output: [0, 2, 3, 5] (O index)

*/