class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        int l = 0;
        int h = n-1;
        int mid = -1;
        bool f = false;

        while(l<h){
            int m  = (l+h)/2;
            if(nums[m]!=nums[m-1] && nums[m]!=nums[m+1]){
                return nums[m];
            }
            else if(nums[m-1]==nums[m]){
                mid = m-1;
                f = true;
            }
            else{
                mid = m;
                f = false;
            }
            

            if((h-mid+1)%2==0){
                if(f){
                    h = mid-1;
                }
                else{
                    h = m-1;
                }
            }
            else{
                if(f){
                    l = m +1;
                }
                else{
                    l = m+2;
                }
            }
        }

        return nums[l];
    }
};