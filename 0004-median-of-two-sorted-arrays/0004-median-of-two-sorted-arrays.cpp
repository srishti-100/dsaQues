class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int p = nums2.size();

        if(n>p){
            vector<int> nums3 = nums2;
            nums2 = nums1;
            nums1 = nums3;
            swap(n,p);
        }

        int req = (n+p);

        int l = 0;
        int h = n;

        while(l<=h){
          int m = (l+h)/2; //2
          int c2 = (req+1)/2-m;
          int l1 = (m==0) ? INT_MIN : nums1[m-1];
          int l2 = (c2 ==0) ? INT_MIN : nums2[c2-1];
          int r1 = (m==n) ? INT_MAX : nums1[m];
          int r2 = (c2 == p) ? INT_MAX : nums2[c2];
        //   int m1 = nums1[m-1];
        //   int m2 = nums2[req-m-1]; //3

          if(l1<=r2 && l2<=r1){
            if((n+p)%2==0) {
                return (max(l1,l2) + min(r1,r2))/2.00000;
            }
            return max(l1,l2);
        
          }
          else if(l1>r2){
            h = m-1;
          }
          else if(l2>r1){
            l = m+1;
          }
        }

        return 0.00000;
    }
};