class Solution {
public:
    set<vector<int>> ans;
    
    void helper(int i, int n, vector<int>& arr,vector<int>v){
        if(i==n){
            sort(v.begin(),v.end());
            ans.insert(v);
            return;
        }
        helper(i+1,n,arr,v);
            
        v.push_back(arr[i]);
        helper(i+1,n,arr,v);        
        v.pop_back();
        
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        int n = nums.size();
        vector<int>v;
        helper(0,n,nums,v);
        vector<vector<int>> res;
        for(auto i:ans){
            res.push_back(i);
        }
        return res;
    }
};