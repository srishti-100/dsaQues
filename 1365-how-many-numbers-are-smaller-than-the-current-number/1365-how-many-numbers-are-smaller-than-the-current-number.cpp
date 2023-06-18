class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
         vector<int> ans ; 
   
    int j = nums.size();
    for(int i=0; i<j ; i++){
        int count =0;
        int element = nums[i];
        for(int p=0;p<j ; p++){
            if(nums[i]>nums[p]){
                count++;
            }
         
        } ans.push_back(count);  
    }
    return ans ; 
    }
};