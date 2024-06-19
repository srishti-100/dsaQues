class Solution {
public:
    int maxProduct(vector<int>& arr) {
        /*
        int n = nums.size();
        int pref = 1;
        int suff =1;
        int maxi = INT_MIN;

        for(int i =0; i<n; i++){
            if(pref==0){
                pref = 1;
                
            }
            if(suff == 0) suff =1;
            
                pref = pref*nums[i];
                suff = suff*nums[n-i-1];

                maxi = max(maxi,max(suff,pref));
            
        }
        return maxi;
        */
        int n = arr.size(); //size of array.

    double pre = 1, suff = 1;
    int ans = INT_MIN;
    for (int i = 0; i < n; i++) {
        if (pre == 0) pre = 1;
        if (suff == 0) suff = 1;
        pre *= arr[i];
        suff *= arr[n - i - 1];
        double temp = pre;
        if(pre<suff) temp = suff;
        if(ans<temp) ans = temp;
        
    }
    return ans;

    }
};