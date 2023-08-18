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
        vector<vector<int>> dp(n+1,vector<int>(n+1,0));
        
        for(int idx =n-1; idx>=0; idx--){
            for(int j =idx-1; j>=-1; j--){
                int l1 = 0;
                int l2 = 0;
                if(j==-1 || nums[idx]>nums[j]){
                    l1 = 1 + dp[idx+1][idx+1];
                }
                l2 = dp[idx+1][j+1];
                dp[idx][j+1]=max(l1,l2);
            }
        }

        return dp[0][0];

    }


};