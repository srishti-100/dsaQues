class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int same = 0;
        int desc = 0;

        for(int i =0; i<nums.size()-1; i++){
            if(nums[i]==nums[i+1]) same++;
            if(nums[i+1]<nums[i]) desc++;
        }

        if(same == nums.size()-1 || desc==nums.size()-1) return false;
        int left= INT_MAX;
        int mid = INT_MAX;

        if(nums.size()<3) return false;

        for(int i =0; i<nums.size(); i++){
            if(nums[i]>mid) return true;

            else if(nums[i]>left && nums[i]<mid){
                mid = nums[i];
            }

            else if(nums[i]<left){
                left = nums[i];
            }

        }
        return false;
    }
};