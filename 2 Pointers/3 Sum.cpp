int Solution::threeSumClosest(vector<int> &a, int B) {
    
    int n = a.size();
    sort(a.begin() , a.end());
    int currentmin = INT_MAX;
    for(int i=0;i<n-2;i++){
        // current fixed element is a[i]
        
        int l = i+1;
        int r = n-1;
        
        while(l<r){
            int sum = a[i] + a[l] + a[r];
            if(abs(1LL*B - sum) < abs(1LL*B - currentmin)){
                currentmin = sum;
            }
            if(sum > B){
                r--;
            }
            else{
                l++;
            }
        }
    }
    
    return currentmin;
}

/*

Given an array S of n integers, find three integers in S such that the sum is closest to a given number, target.
Return the sum of the three integers.

Assume that there will only be one solution

Example:
given array S = {-1 2 1 -4},
and target = 1.

The sum that is closest to the target is 2. (-1 + 2 + 1 = 2)


*/