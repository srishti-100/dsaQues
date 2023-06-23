class Solution {
public:
    set<vector<int>> s;

    void helper(int i, int n, int target, vector<int>& arr,vector<int> v){
        if(i==n) return;
        if(target<0) return;

        if(target==0){
            sort(v.begin(), v.end());
            s.insert(v);
            return;
        }

        for(int j= i; j<n; j++){
            v.push_back(arr[j]);
            helper(j,n,target-arr[j],arr,v);
            v.pop_back();
        }

    }


    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int n = candidates.size();
        vector<int>v;
        vector<vector<int>> ans;
        helper(0,n,target,candidates,v);
        for(auto i: s){
            ans.push_back(i);
        }
        return ans;
    }
};