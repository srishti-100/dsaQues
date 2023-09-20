class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
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
    }
};