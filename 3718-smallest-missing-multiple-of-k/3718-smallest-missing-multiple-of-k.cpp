class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        set<int> st;

        for(int i =0; i<nums.size(); i++){
            st.insert(nums[i]);
        }

        for(int i = 1; i<=100; i++){
            if(st.find(k*i)==st.end()){
                return k*i;
            }
        }
        return 101;
    }
};