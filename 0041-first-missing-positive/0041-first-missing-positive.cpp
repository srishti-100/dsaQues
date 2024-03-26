class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        unordered_set<int> st;
        // int mini = INT_MAX;
        int maxi = 0;
        
        for(int i =0; i<nums.size(); i++){
            if(nums[i]>=0){
                st.insert(nums[i]);
                if(nums[i]>maxi){
                    maxi = nums[i];
                }
            }
        }
        
        for(int i =1; i<maxi; i++){
            if(st.find(i)==st.end()){
                return i;
            }
        }
        return maxi+1;
    }
};