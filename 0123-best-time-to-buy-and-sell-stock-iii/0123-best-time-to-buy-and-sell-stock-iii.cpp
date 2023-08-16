class Solution {
private:
    int helper(int i,int buy, int n, int cap, vector<int>& prices, vector<vector<vector<int>>>& dp){

        if(i==n || cap==0) return 0;
        if(dp[i][buy][cap]!=-1) return dp[i][buy][cap];
        int profit = INT_MIN;
        if(buy){
            profit = max(-prices[i] + helper(i+1,0,n,cap,prices,dp), helper(i+1,buy,n,cap,prices,dp));
        }
        else{
            profit = max(prices[i] + helper(i+1,1,n,cap-1,prices,dp), helper(i+1,0,n,cap,prices,dp));
        }
        dp[i][buy][cap] = profit;
        return profit;
    }


public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(2,vector<int>(3,-1)));
        return helper(0,true,n,2,prices,dp);
    }
};