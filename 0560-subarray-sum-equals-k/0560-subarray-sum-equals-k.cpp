class Solution {
public:
    //brute force
    /*
    int subarraySum(vector<int>& nums, int k) {
        int count = 0;
        int n= nums.size();
        for(int i =0; i<n; i++){
            int sum = 0;
            for(int j = i; j<n; j++){

                sum+=nums[j];
                if(sum==k) count++;
            }
        }

        return count;
    }
    */

    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> prefix(n,0);
        prefix[0]=nums[0];

        for(int i =1; i<n; i++){
            prefix[i]=prefix[i-1]+nums[i];
        }

        unordered_map<int,int> mp;
        int count = 0;

        for(int i =0; i<n; i++){    
            if(prefix[i]==k) count++;

            if(mp.find(prefix[i]-k)!=mp.end()){
                count+=mp[prefix[i]-k];
            }
            mp[prefix[i]]++;
            
        }

        return count;

    }

};