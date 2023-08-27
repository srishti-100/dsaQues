class Solution {
private:
    int helper(int s, int e, vector<int>& arr, vector<vector<int>>& dp){
        if(s>e) return 0;
        if(dp[s][e]!=-1) return dp[s][e];
        int maxi = INT_MIN;

        for(int i = s; i<=e; i++){
            int cost = arr[s-1]* arr[i]* arr[e+1] + helper(s,i-1,arr,dp) + helper(i+1,e,arr,dp);
            maxi = max(maxi,cost);
        }
        return dp[s][e]=maxi;
    }
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        nums.insert(nums.begin(),1);
        nums.push_back(1);
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        return helper(1,n,nums,dp);
    }
};