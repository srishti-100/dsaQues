class Solution {
public:
    int maxProduct(int n) {
        vector<int> nums;

        while(n!=0){
            int rem = n%10;
            n/=10;
            nums.push_back(rem);
        }

        int s = nums.size();
        sort(nums.begin(), nums.end());

        return nums[s-1] * nums[s-2];
    }
};