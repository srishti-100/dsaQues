class Solution {
    /*
private:
    int helper(int idx, int target, vector<int>& nums,vector<vector<int>>& dp){
        if(target<0) return 0;
        if(target==0){
            return 1; 
        }
        if(idx==nums.size()){
            return 0;
        }
        if(dp[idx][target]!=-1) return dp[idx][target];
        int count = 0;
        for(int i = 0; i<nums.size(); i++){
            count+=helper(i, target-nums[i], nums, dp);
        }
        dp[idx][target] = count;
        return count;
    }
public:
    int combinationSum4(vector<int>& nums, int target) {
        
        int n = nums.size();
        vector<vector<int>> dp(n,vector<int>(target+1,-1));
        return helper(0,target, nums,dp);
    }
    */
public:
    int combinationSum4(vector<int>& nums, int target) {
        
        int n = nums.size();
        vector<unsigned long long> dp(target+1,0);
       
       dp[0] =1;

        for(int i = 1; i<=target; i++){
            
            for(int j = 0; j<nums.size(); j++){
                if(i-nums[j]>=0)
                    dp[i]+=dp[i-nums[j]];
            }
        }

        return dp[target];

    }

};