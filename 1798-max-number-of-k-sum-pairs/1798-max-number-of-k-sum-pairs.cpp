class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        /*
        sort(nums.begin(),nums.end());

        unordered_map<int,int> mp;

        for(int i =0; i<nums.size(); i++){
            mp[nums[i]]++;
        }

        int cnt = 0;
        for(int i =0; i<nums.size(); i++){
            mp[nums[i]]--;
            if(mp.find(k-nums[i])!=mp.end() && mp[k-nums[i]]>0){
                mp[k-nums[i]]--;
                cnt++;
            }
        }
        return cnt;
        */

        sort(nums.begin(), nums.end());
        int n = nums.size();
        int i = 0;
        int j = n-1;
        int cnt = 0;

        while(i<j){
            if(nums[i]+nums[j]==k){
                i++;
                j--;
                cnt++;
            }
            else if(nums[i]+nums[j]>k){
                j--;
            }
            else
                i++;
        }

        return cnt;
    }
};