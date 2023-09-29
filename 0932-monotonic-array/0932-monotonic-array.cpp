class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        bool inc = false;
        for(int i =0; i<nums.size()-1; i++){
            if(nums[i]>nums[i+1]){
                inc = true;
                break;
            }

        }
        if(inc==false) return true;

        inc = false;
        for(int i =0; i<nums.size()-1; i++){
            if(nums[i]<nums[i+1]){
                inc = true;
                break;
            }

        }
        if(inc==false) return true;
        return false;
    }
};