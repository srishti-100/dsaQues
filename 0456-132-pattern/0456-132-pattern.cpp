class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        
        //O(n^3) TC
        /*
        for(int i =0; i<nums.size(); i++){

            for(int j = i+1; j<nums.size(); j++){

                for(int k = j+1; k<nums.size(); k++){

                    if(nums[i] < nums[k] && nums[k] < nums[j]){
                        return true;
                    }
                }
            }
        }
        return false;
        */

        //O(N) TC
        //O(N) SC

        stack<pair<int,int>> st;
        int currMin = nums[0];

        for(int i =0; i<nums.size(); i++){
            
            while(!st.empty() && nums[i]>=st.top().first){
                st.pop();
            }

            if(!st.empty() && nums[i]>st.top().second){
                return true;
            }

            st.push(make_pair(nums[i],currMin));
            currMin = min(currMin,nums[i]);

        }
        return false;
    }
};