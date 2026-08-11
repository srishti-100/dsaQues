class Solution {
public:
    void helper(vector<bool>& visited, vector<int>&nums, vector<vector<int>>& ans, vector<int> temp){
        if(temp.size()==nums.size()){
            ans.push_back(temp);
            return;
        }

        for(int i =0; i<nums.size(); i++){
            if(!visited[i]){
                visited[i] = true;
                temp.push_back(nums[i]);
                helper(visited, nums, ans, temp);
                temp.pop_back();
                visited[i] = false;
            }
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        vector<bool> visited(n,false);

        vector<vector<int>> ans;
        vector<int> temp;

        helper(visited, nums, ans,temp);
        return ans;
    }
};