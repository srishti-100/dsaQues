class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        unordered_set<int> st;
        int smallest = INT_MAX;
        int largest = INT_MIN;

        for(auto num:nums){
            st.insert(num);
            smallest = min(num,smallest);
            largest = max(largest, num);
        }

        vector<int> ans;
        for(int i = smallest; i<=largest; i++){
            if(st.find(i)==st.end()){
                ans.push_back(i);
            }
        }

        return ans;
    }
};