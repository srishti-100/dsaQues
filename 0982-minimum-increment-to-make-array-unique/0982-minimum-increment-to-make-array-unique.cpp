class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        /*
        set<int> st;
        int n = nums.size();
        int i =1;
        int move = 0;
        sort(nums.begin(),nums.end());
        st.insert(nums[0]);
        int lastInsertedVal = nums[0];
        
        while(i<n){
            int num = nums[i];
            if(st.find(num)==st.end()){
                move+=0;
                lastInsertedVal = num;
                st.insert(num);
            }
            else{
                move+=(lastInsertedVal+1-num);
                lastInsertedVal+=1;
                st.insert(lastInsertedVal);
            }
            i++;
        }
        return move;
        */

        sort(nums.begin(), nums.end());

        int lastInsertedVal = 0;
        int move = 0;

        for(auto num: nums){
            lastInsertedVal = max(lastInsertedVal, num);
            move+=lastInsertedVal - num;
            lastInsertedVal+=1;
        }

        return move;
    }
};