class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();

        vector<int> leftArray(n,1) , rightArray(n,1);

        for(int i = 1; i<n; i++){
            leftArray[i] = leftArray[i-1]*nums[i-1];
        }

        for(int i = n-2; i>=0; i--){
            rightArray[i] = rightArray[i+1]*nums[i+1];
        }

        vector<int> ans(n,1);

        for(int i =0; i<n; i++){
            ans[i]=leftArray[i]*rightArray[i];
        }
        return ans;
    }
};