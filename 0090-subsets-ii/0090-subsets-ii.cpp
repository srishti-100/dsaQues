class Solution {
public:
/*
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
*/
    void helper(vector<int>& nums, int idx, vector<vector<int>>& ans, vector<int>& temp){

       
        ans.push_back(temp);
       

        for(int i = idx; i<nums.size(); i++){
            if(i!=idx && nums[i]==nums[i-1]) continue;

            temp.push_back(nums[i]);
            helper(nums, i+1, ans, temp);
            temp.pop_back();
        }

    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        /*
        vector<int> temp;
        set<vector<int>> st;
        sort(nums.begin(), nums.end());
        helper(nums, 0, st, temp);

        vector<vector<int>> ans (st.begin(), st.end());
        // sort(ans.begin(), ans.end());
        return ans;
        */

        vector<int> temp;
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        helper(nums, 0, ans, temp);

        return ans;   
    }
};