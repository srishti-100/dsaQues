class Solution {
public:
/*
    void helper(vector<int>& vec, int target, int idx, set<vector<int>>& st, vector<int>& temp){
        if(idx == vec.size()){
            if(target==0){
                // sort(temp.begin(), temp.end());
                st.insert(temp);
            }
            return;
        }

        if(target < 0) return;

        temp.push_back(vec[idx]);
        helper(vec,target - vec[idx], idx+1, st, temp);
        temp.pop_back();

        helper(vec, target, idx+1, st, temp);

    }

*/  
    void helper(vector<int>& vec, int target, int idx, vector<vector<int>>& ans, vector<int>& temp){
        if(target == 0){
            ans.push_back(temp);
            return;
        }


        

        for(int i = idx; i<vec.size(); i++){
            if(vec[i] > target) break;
            if(i > idx && vec[i]==vec[i-1]) continue;
            temp.push_back(vec[i]);
            helper(vec, target - vec[i], i+1, ans, temp);
            temp.pop_back();
        }

        

    }


    vector<vector<int>> combinationSum2(vector<int>& nums, int target) {
       
        /*
        set<vector<int>> s;
        vector<int> temp;
        sort(nums.begin(), nums.end());
        helper(nums, target, 0, s, temp);

        vector<vector<int>> ans(s.begin(), s.end());

        return ans;
        */

        vector<vector<int>> ans;
        vector<int> temp;
        sort(nums.begin(), nums.end());
        helper(nums, target, 0,ans, temp);
        return ans;
    }
};