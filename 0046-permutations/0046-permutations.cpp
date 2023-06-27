class Solution {
public:
    void helper(vector<int>& visited, vector<int>& r, vector<int>& nums, vector<vector<int>>& ans){
        if(r.size()==nums.size()){
            ans.push_back(r);
            return;
        }

        for(int i =0; i<nums.size(); i++){
            if(visited[i]==1) continue;
            r.push_back(nums[i]);
            visited[i]=1;
            helper(visited, r, nums, ans);
            visited[i]=0;
            r.pop_back();
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        vector<int> visited(n,0);
        vector<int> r;
        vector<vector<int>> ans;
        helper(visited,r, nums, ans);
        return ans;
    }
};