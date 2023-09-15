class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        /*
        int n = nums.size();
        vector<int> left(n);
        vector<int> right(n);

        left[0] = 1;
        right[n-1] = 1;

        for(int i =1; i<n; i++){
            left[i] = left[i-1]*nums[i-1];
        }

        for(int j = n-2; j>=0; j--){
            right[j] = right[j+1]*nums[j+1];
        }

        vector<int> ans(n,0);
        for(int i = 0; i<n; i++){
            ans[i] = right[i]*left[i];
        }

        return ans;
        */

        int n = nums.size();
        vector<int> ans(n,0);

        ans[0] =1;
        int right =  1;
        for(int i =1; i<n; i++){
            ans[i] = ans[i-1]*nums[i-1];
            
        }

        for(int j = n-1; j>=0; j--){
            ans[j] = right*ans[j];
            right = right*nums[j];
        }

        
        return ans;

    }
};