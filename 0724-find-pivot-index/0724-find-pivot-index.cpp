class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        /*
        int sum = 0;

        for(int i =0; i<nums.size(); i++){
            sum+=nums[i];
        }

        int leftSum =0;
        int rightSum = sum;

        for(int i =0; i<nums.size(); i++){
            rightSum-=nums[i];
            if(leftSum==rightSum) return i;
            leftSum +=nums[i];
        }

        return -1;
        */

        int sum = 0;

        for(int i =0; i<nums.size(); i++){
            sum+=nums[i];
        }

        int leftSum =0;

        for(int i =0; i<nums.size(); i++){
            if(leftSum*2==sum-nums[i]){
                return i;
            }
            leftSum+=nums[i];
        }
        return -1;

    }
};