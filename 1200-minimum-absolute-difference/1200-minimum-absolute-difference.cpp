class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int n = arr.size();
        int minAbsDifference = INT_MAX;
        for(int i =0; i<n-1; i++){
            minAbsDifference = min(minAbsDifference, abs(arr[i+1]-arr[i]));
        }

        vector<vector<int>> ans;
        for(int i = 0; i<n-1; i++){
            
                if(abs(arr[i+1]-arr[i])==minAbsDifference){
                    ans.push_back({arr[i],arr[i+1]});
                }
            
        }
        return ans;
    }
};