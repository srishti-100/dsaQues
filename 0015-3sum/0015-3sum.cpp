class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        set<vector<int>> s;
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());

        /* TLE
        for(int i = 0; i<n; i++){
            int s1 = 0 - nums[i];
            for(int j = i+1; j< n; j++){
                int s2 = s1-nums[j];
                for(int k = j+1; k<n; k++){
                    if(nums[k]==s2){
                        s.insert({nums[i],nums[j],nums[k]});
                    } 
                }
            }
        }
        */

        

        for(int i = 0; i<n-2; i++){
            int l = i+1;
            int h = n-1;
            while(l<h){
                
                if(nums[l]+nums[h]+nums[i]==0){
                    s.insert({nums[i],nums[l],nums[h]});
                    l++;
                    h--;
                }
                else if(nums[l]+nums[h]+nums[i] < 0) l++;
                else 
                    h--;
                    
            }
        }

        for(auto v : s){
            ans.push_back(v);
        }
        return ans;
    }
};