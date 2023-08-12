class Solution {
private:
    int helper(vector<int>& coins, int amount, vector<int>& dp){
        if(amount==0) return 0;
        if(dp[amount]!=-1) return dp[amount];
        int mini = INT_MAX;
        for(int i = 0; i<coins.size(); i++){
            if(coins[i]<=amount){
                int a = helper(coins, amount-coins[i],dp);
                if(a!=INT_MAX)
                    mini = min(mini,1+a);
            }
        }
        return dp[amount]=mini;

    }
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1,-1);
        int a = helper(coins,amount,dp);
        return (a==INT_MAX)?-1:a;
    }
};