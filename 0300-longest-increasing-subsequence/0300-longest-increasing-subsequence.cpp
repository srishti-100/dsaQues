class Solution {
private:
    int helper(int idx, int prev_idx, vector<int>& nums,vector<vector<int>>& dp){
        if(idx==nums.size()) return 0;
        if(dp[idx][prev_idx+1]!=-1) return dp[idx][prev_idx+1];
        int l1 = 0;
        int l2 = 0;
        if(prev_idx==-1 || nums[idx]>nums[prev_idx]){
            l1 = 1 + helper(idx+1,idx,nums,dp);
        }
        l2 = helper(idx+1,prev_idx,nums,dp);
        return dp[idx][prev_idx+1]=max(l1,l2);
    }
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n,vector<int>(n+1,-1));
        return helper(0,-1, nums, dp);
    }


};