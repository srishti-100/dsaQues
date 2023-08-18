class Solution {

public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<int> dp(n,1);
        vector<int> backTrack(n);
        
        for(int i =0; i<n; i++){
            backTrack[i]=i;
        }
        int maxIdx = 0;

        for(int i =1; i<n; i++){
            for(int j =0; j<i; j++){
                if(nums[i]%nums[j]==0){
                    if(dp[j]+1>dp[i]){
                        backTrack[i]=j;
                        dp[i]=1+dp[j];
                    }
                }
            }
            if(dp[i]>dp[maxIdx]){
                maxIdx = i;
            }
        }

        vector<int> ans;
        ans.push_back(nums[maxIdx]);
        int i = maxIdx;
        while(backTrack[i]!=i){
            ans.push_back(nums[backTrack[i]]);
            i = backTrack[i];
        }
        
        reverse(ans.begin(), ans.end());
        
        return ans;
        
    }
};