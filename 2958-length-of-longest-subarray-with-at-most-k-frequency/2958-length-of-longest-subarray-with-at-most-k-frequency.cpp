class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        int n = nums.size();
        int i = 0;
        int j = 0;
        int maxi = INT_MIN;

        while(i<n && j<n){
            if(mp[nums[j]]<k){
                mp[nums[j]]++;
                j++;
            }
            else{
                int val = nums[j];
                mp[nums[j]]++;
                while(mp[val] >k){
                    mp[nums[i]]--;
                    i++;
                }
                j++;
            }
            maxi = max(maxi, j-i);
        }

        maxi = max(maxi, j-i);
        return maxi;

    }
};