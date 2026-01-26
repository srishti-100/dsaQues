class Solution {
public:
    int minimumPrefixLength(vector<int>& nums) {
        int n = nums.size();
        int idx = n-1;

        while(idx >0){
            if(nums[idx-1] >= nums[idx]){
                // idx = i;
                break;
            }
            idx--;
        }
        
        return idx;
    }
};