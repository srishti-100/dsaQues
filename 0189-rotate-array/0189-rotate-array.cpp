class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k%n;

        if(k<0){
            k+=n;
        }

        

        reverse(nums.begin(), nums.begin()+n-k);
        
        reverse(nums.begin(),nums.end());
        reverse(nums.begin(),nums.begin()+k);
    }
};