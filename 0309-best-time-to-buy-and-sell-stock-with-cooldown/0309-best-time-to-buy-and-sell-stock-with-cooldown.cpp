class Solution {
private:
    int helper(int i, bool buy, vector<int>& values, int n, vector<vector<int>>& dp){
    if(i>=n) return 0;
    if(dp[i][buy]!=-1) return dp[i][buy];
    int profit = INT_MIN;
    if(buy){
        profit = max(-values[i] + helper(i+1,false,values,n,dp), 0+ helper(i+1,true,values,n,dp));
    }
    else{
        profit = max(values[i] + helper(i+2,true,values,n,dp), 0+ helper(i+1,false,values,n,dp));
    }
    dp[i][buy]=profit;
    return profit;
}

public:
    // int maxProfit(vector<int>& prices) {
    //     int n = prices.size();
    //     vector<vector<int>> dp(n,vector<int>(2,-1));
    //     return helper(0,1,prices, n, dp);
    // }

    int maxProfit(vector<int>& values) {
        int n = values.size();
        vector<vector<int>> dp(n+2,vector<int>(2,0));
        
        for(int i =n-1; i>=0; i--){
            for(int buy = 0; buy<2; buy++){
                int profit = INT_MIN;
                if(buy){
                    profit = max(-values[i] + dp[i+1][0], 0+ dp[i+1][1]);
                }
                else{
                    profit = max(values[i] + dp[i+2][1], 0+ dp[i+1][0]);
                }
                dp[i][buy]=profit;
            }
        }

        return dp[0][1];

    }
    
};


