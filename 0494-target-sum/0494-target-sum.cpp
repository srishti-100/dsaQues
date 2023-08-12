class Solution {
private:
    void helper(int idx, int n, int target, vector<int>& nums, int&count){
        if(idx==n){
            if(target==0){
                count++;
            }
            return;
        }

        helper(idx+1, n, target-nums[idx],nums,count);
        helper(idx+1,n,target+nums[idx],nums,count);

    }

public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int count =0;
        helper(0,nums.size(), target,nums,count);
        return count;
    }
};