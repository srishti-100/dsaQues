class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        map<int,int> mp;
        int n = nums2.size();
        stack<int> st;
        vector<int> ans(n,-1);

        for(int i = nums2.size()-1; i>=0; i--){
            while(!st.empty() && st.top()<nums2[i]){
                st.pop();
            }
            if(st.empty()){
                ans[i] = -1;
            }
            else{
                ans[i] = st.top();
            }

            mp[nums2[i]] = ans[i];
            st.push(nums2[i]);

        }

        vector<int> finalAns;
        for(int i =0; i<nums1.size(); i++){
            finalAns.push_back(mp[nums1[i]]);
        }

        return finalAns;

        
    }
};