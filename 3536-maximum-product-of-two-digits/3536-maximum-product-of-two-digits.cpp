class Solution {
public:
    int maxProduct(int n) {
        int maxi = INT_MIN;
        int secondMaxi = INT_MIN;

        while(n!=0){
            int rem = n%10;
            if(rem>maxi){
                secondMaxi = maxi;
                maxi = rem;
            }
            else if(rem > secondMaxi){
                secondMaxi = rem;
            }
        n/=10;
        }

        return maxi*secondMaxi;

        /*
        vector<int> nums;

        while(n!=0){
            int rem = n%10;
            n/=10;
            nums.push_back(rem);
        }

        int s = nums.size();
        sort(nums.begin(), nums.end());

        return nums[s-1] * nums[s-2];
        */
    }
};