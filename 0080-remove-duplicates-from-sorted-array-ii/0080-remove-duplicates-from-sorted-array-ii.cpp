class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i = 0;
        int start = nums[0];
        int n = nums.size();
        int count = 0;

        while(i<n){
            if(start ==nums[i]){
                if(count < 2){
                    count++;
                    i++;
                }
                else{
                    nums[i] = INT_MAX;
                    i++;
                }
            }
            else{
                start = nums[i];
                count = 0;
            }
        }

        sort(nums.begin(), nums.end());
        i =0;
        while(i<n){
            if(nums[i]!=INT_MAX){
                i++;
            }
            else
                break;
        }
        return i;
    }
};