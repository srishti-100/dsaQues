class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int countNeg = 0;
        int n = nums.size();
        sort(nums.begin(), nums.end());

        for(auto i: nums){
            if(i>=0) break;
            countNeg+=(i<0)?1:0;
        }

        int val1 = INT_MIN;

        if(countNeg >=2){
            val1 = nums[0]*nums[1]*nums[n-1];
            
        }
        int val2 = nums[n-1]*nums[n-2]*nums[n-3];

        return max(val1, val2);
    }
};