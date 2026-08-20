class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        vector<int> arr1, arr2;

        arr1.push_back(nums[0]);
        arr2.push_back(nums[1]);

        for(int i = 2; i<nums.size(); i++){
            int n = arr1.size();
            int m = arr2.size();

            if(arr1[n-1] > arr2[m-1]){
                arr1.push_back(nums[i]);
            }
            else{
                arr2.push_back(nums[i]);
            }
        }

        vector<int> ans;
        ans.insert(ans.end(), arr1.begin(), arr1.end());
        ans.insert(ans.end(), arr2.begin(), arr2.end());

        return ans;
    }
};