class Solution {
public:
    int removeDuplicates(vector<int>& arr) {
        int i = 1;
        int j = 1;
        int n = arr.size();
        while(j<n){
            if(arr[j]==arr[i-1]){
                j++;
            }
            else{
                arr[i]=arr[j];
                i++;
                j++;
            }
        }
        return i;
    }
};