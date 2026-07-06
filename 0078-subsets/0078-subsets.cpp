class Solution {
public:
    void helper(vector<int>& nums, vector<vector<int>>& ans, int idx, int n, vector<int>& temp){
        if(idx == n){ 
            ans.push_back(temp);
            return;
        }

        //not pick
        helper(nums, ans, idx+1, n, temp);

        //pick
        temp.push_back(nums[idx]);
        helper(nums,ans,idx+1,n, temp);
        temp.pop_back();
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;

        helper(nums, ans, 0, nums.size(), temp);

        return ans;

    }
};