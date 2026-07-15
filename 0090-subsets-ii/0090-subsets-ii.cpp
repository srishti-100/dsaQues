class Solution {
public:
    void helper(vector<int>& nums, int idx, set<vector<int>>& st, vector<int>& temp){
        if(idx >= nums.size()){
            // sort(temp.begin(), temp.end());
            st.insert(temp);
            return;
        }

        //not pick
        helper(nums,idx+1, st, temp);

        //pick
        temp.push_back(nums[idx]);
        helper(nums,idx+1, st, temp);
        temp.pop_back();
        
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> temp;
        set<vector<int>> st;
        sort(nums.begin(), nums.end());
        helper(nums, 0, st, temp);

        vector<vector<int>> ans (st.begin(), st.end());
        // sort(ans.begin(), ans.end());
        return ans;
    }
};