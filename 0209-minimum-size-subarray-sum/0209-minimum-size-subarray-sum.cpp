class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int i =0; int j = 0;

        int n = nums.size();
        int l =0;
        long long sum =0;
        int ml = INT_MAX;
        while(j<n){
            sum+=nums[j];
            while(sum>=target){
                l = j-i+1;
                ml = min(l,ml);
                sum-=nums[i];
                i++;
                
            }
            j++;
        }

        if(ml==INT_MAX) return 0;

        return ml;
    }
};