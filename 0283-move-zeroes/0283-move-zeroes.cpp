class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        /*
        int n = nums.size();

        vector<int> ans(n,0);
        int k = 0;

        for(int i =0; i<n; i++){
            if(nums[i]==0)continue;
            ans[k]=nums[i];
            k++;
        }
        nums = ans;
        */

        
        int i = 0;

        for(int j =0; j<nums.size(); j++){
            if(nums[j]!=0){
                swap(nums[i++],nums[j]);
            }
        }

    }
};