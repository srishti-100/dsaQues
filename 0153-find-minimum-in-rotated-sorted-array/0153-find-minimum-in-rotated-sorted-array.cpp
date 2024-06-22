class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int ans = INT_MAX;

        int l =0;
        int h = n-1;

        while(l<=h){
            int m = (l+h)/2;

            if(nums[l]<nums[h]){
                ans = min(nums[l],ans);
                break;
            }

            if(nums[l]<=nums[m]){

                ans = min(ans,nums[l]);
                l = m+1;
            }
            else{
                ans = min(ans,nums[m]);
                h = m-1;
            }
        }
        return ans;
    }
};