class Solution {
public:
    void helper(vector<int>& nums, int target, int idx, set<vector<int>>& st, vector<int>& temp){
        if(idx >= nums.size()){
            if(target==0){
                st.insert(temp);
            }
            return;
        }
        if(target == 0){
            st.insert(temp);
            return;
        }
        if(target < nums[idx]) return;

        temp.push_back(nums[idx]);
        helper(nums,target-nums[idx], idx, st, temp);
        temp.pop_back();

        helper(nums, target, idx+1, st,temp);

    }


    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<int> temp;
        set<vector<int>> st;
        helper(nums, target, 0, st, temp);

        vector<vector<int>> ans(st.begin(), st.end());
        return ans;
    }
};