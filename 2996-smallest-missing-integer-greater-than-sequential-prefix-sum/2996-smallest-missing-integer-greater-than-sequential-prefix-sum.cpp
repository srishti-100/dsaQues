class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int sum = nums[0];
        int n = nums.size();
        unordered_set<int> st;
        int maxi = INT_MIN;

        for(int i =0; i<n; i++){
            st.insert(nums[i]);
            maxi = max(maxi,nums[i]);
        }

        int idx = -1;
        for(int i=1; i<n; i++){
            if(nums[i]!=nums[i-1]+1){
                idx = i;
                break;
            }
            sum+=nums[i];
        }

        while(true){
            if(st.find(sum)==st.end()){
                return sum;
            }
            sum++;
        }

        return -1;
        
    }
};