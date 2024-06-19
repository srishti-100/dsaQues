class Solution {
public:
    int maxProfit(vector<int>& nums) {
        int lps = nums[0];
        int profit =0, max_profit = 0;

        for(int i =1; i<nums.size(); i++){
             profit = nums[i]-lps;
             lps= min(lps,nums[i]);
             max_profit = max(max_profit,profit);
        }
        return max_profit;
    }
};