class Solution {
public:
    int search(vector<int>& arr, int target) {
        int n = arr.size();
        int l = 0;
        int h = n-1;

        while(l<=h){
            int m = (l+h)/2;

            if(arr[m]==target){
                return m;
            }
            else if(arr[m]>=arr[l]){ //left side sorted
                if(arr[l]<=target && target<=arr[m]){ //element found in left sorted half
                    h = m-1;
                }
                else{
                    l= m+1;
                }
            }
            else{ //right side sorted
                if(target<=arr[h] && target>=arr[m]){
                    l = m+1;
                }
                else{
                    h = m-1;
                }
            }
        }

        return -1;
        
    }
};