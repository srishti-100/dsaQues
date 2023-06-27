class Solution {
public:
    set<vector<int>> ans;
    
    void helper(int i, int n, vector<int>& arr,vector<int>v){
        if(i==n){
            ans.insert(v);
            return;
        }
        
        helper(i+1,n,arr,v);
            
        v.push_back(arr[i]);
        helper(i+1,n,arr,v);        
        v.pop_back();
       

        // for(int j = i; j<n; j++){
        //     if (j != i && arr[i] == arr[i - 1]) continue;
        //     v.push_back(arr[i]);
        //     helper(i+1,n,arr,v);        
        //     v.pop_back();
        //     helper(i+1,n,arr,v);

        // }
        
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        int n = nums.size();
        vector<int>v;
        sort(nums.begin(),nums.end());
        helper(0,n,nums,v);
        vector<vector<int>> res;
        for(auto i:ans){
            res.push_back(i);
        }
        return res;
    }
};