class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int arrSum = 0;

        for(int i =0; i<nums.size(); i++){
            arrSum+=nums[i];
        }

        int needSum = arrSum-x;
        if(needSum==0) return nums.size();
        int left = 0;
        int maxLen = 0;
        int right = 0;
        int currSum = 0;

        while(right<nums.size()){
            currSum+=nums[right];

            while(left<=right && currSum>needSum){               
                currSum-=nums[left];
                left++;
            }
            
            if(currSum == needSum){
                maxLen = max(maxLen,right-left+1);
            }

            
            right++;
        }

        if(maxLen==0) return -1;
        return nums.size()-maxLen;
    }
};