class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        // vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(2,vector<int>(3,0)));
        //so

        vector<vector<int>> last( 2,vector<int>(k+1,0));
        vector<vector<int>> curr( 2,vector<int>(k+1,0));

        for(int i = n-1; i>=0; i--){
            for(int buy = 0; buy<2; buy++){
                for(int cap = 1; cap<=k; cap++){
                    int profit = INT_MIN;
                    if(buy){
                        profit = max(-prices[i] + last[0][cap], last[buy][cap]);
                    }
                    else{
                        profit = max(prices[i] + last[1][cap-1], last[0][cap]);
                    }
                    curr[buy][cap] = profit;
                }
            }
            last = curr;
        }
    return last[1][k];
    }
};