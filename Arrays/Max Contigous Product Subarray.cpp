class Solution {
public:
    int maxProduct(vector<int>& nums) {
        
        if(nums.size() == 0){
            return 0;
        }
        if(nums.size() == 1){
            return nums[0];
        }
        
        int currmax = 1;
        int maxprod = 0;
        
        for(int i=0;i<nums.size();i++){
            currmax = currmax*nums[i];
            maxprod = max(maxprod , currmax);
            if(currmax == 0){
                currmax = 1;
            }
        }
        
        currmax = 1;
        
        for(int i=nums.size()-1;i>=0;i--){
            currmax = currmax*nums[i];
            maxprod = max(maxprod , currmax);
            if(currmax == 0){
                currmax = 1;
            }
        }
        
        
        return maxprod;
    }
};