class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> prefSum(n,0);
        prefSum[0]=nums[0];
        for(int i =1; i<n; i++){
            prefSum[i]=nums[i]+prefSum[i-1];
        }

        int i = 0;
        int j =0;
        unordered_map<int,int> mp;
        mp[0]=-1;
        while(i<n){
            if(k!=0){
                prefSum[i]%=k;
            }
            if(mp.count(prefSum[i])>0){
                if(i-mp[prefSum[i]]>1) return true;
            }
            else{
                mp[prefSum[i]] = i;
            }
            i++;
        }
        return false;
    }
};