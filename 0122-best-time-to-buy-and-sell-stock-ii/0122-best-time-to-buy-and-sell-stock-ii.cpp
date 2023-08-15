class Solution {
public:
    int maxProfit(vector<int>& values) {
        int n = values.size();
        vector<vector<int>> dp(n+1,vector<int>(2,-1));
        dp[n][0]=dp[n][1]=0;
        for(int i =n-1; i>=0; i--){
            for(int j = 0; j<2; j++){
                int profit = LONG_MIN;
                if(j){
                    profit = max(-values[i] + dp[i+1][0], 0+ dp[i+1][1]);
                }
                else{
                    profit = max(values[i] + dp[i+1][1], 0+ dp[i+1][0]);
                }
                dp[i][j]=profit;
            }
        }

        return dp[0][1];
    }
};
/*
long helper(int i, bool buy, long* values, int n, vector<vector<long>>& dp){
    if(i==n) return 0;
    if(dp[i][buy]!=-1) return dp[i][buy];
    long profit = LONG_MIN;
    if(buy){
        profit = max(-values[i] + helper(i+1,false,values,n,dp), 0+ helper(i+1,true,values,n,dp));
    }
    else{
        profit = max(values[i] + helper(i+1,true,values,n,dp), 0+ helper(i+1,false,values,n,dp));
    }
    dp[i][buy]=profit;
    return profit;
}

long getMaximumProfit(long *values, int n)
{
    
        vector<vector<long>> dp(n,vector<long>(2,-1));
        return helper(0,1,values, n, dp);
}
*/


