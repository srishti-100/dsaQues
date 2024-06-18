class Solution {
public:
    int binarySearchHighestIndex(const std::vector<pair<int,int>>& arr, int target) {
        int low = 0;
        int high = arr.size() - 1;
        int result = -1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (arr[mid].first <= target) {
                result = mid;  // Update result to mid, since arr[mid] is <= target
                low = mid + 1;  // Move right to find a possibly higher index
            } else {
                high = mid - 1;  // Move left if arr[mid] > target
            }
        }

        return result;
    }

    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        int n = difficulty.size();
        int m = worker.size();
        int max_profit = 0;
        vector<pair<int,int>> vec;

        for(int i =0; i<n; i++){
            vec.push_back(make_pair(difficulty[i],profit[i]));
        }

        sort(vec.begin(), vec.end());

        for (int i = 1; i < n; i++) {
            vec[i].second = max(vec[i].second, vec[i - 1].second);
        }

        for(int i =0; i<m; i++){
            int idx = binarySearchHighestIndex(vec,worker[i]);

            if(idx == -1){
                continue;
            }
            else{
                max_profit+=vec[idx].second;
            }
        }
        return max_profit;
    }
};