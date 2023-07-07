class Solution {
public:
    int searchInsert(vector<int>& Arr, int k) {
        // int l = 0;
        // int h = nums.size()-1;

        // while(l<h){
        //     int m = (l+h)/2;
        //     if(nums[m]==target) return m;
        //     else if(nums[m]>target) h = m-1;
        //     else l = m+1;
        // }
        // if(nums[l]>=target) return l;
        // return l+1;

        int N = Arr.size();
        int l =0;
        int h = N-1;
        int idxIns =-1;
        
        while(l<=h){
            int m = (l+h)/2;
            
            if(Arr[m]<k){
                l = m+1;
            }
            else{
                idxIns = m;
                h = m-1;
            }
        }
        if(idxIns==-1){
            if(Arr[0]>k) return 0;
            else return N;
        }
        return idxIns;

    }
};