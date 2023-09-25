class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        unordered_map<string,int> rows;
        unordered_map<string,int> cols;
        int n = grid.size();
        for(int i =0; i<n; i++){
            string t;
            for(int j =0; j<n; j++){
                t+=to_string(grid[i][j])+'#';
            }
            rows[t]++;
        }

        for(int i =0; i<n; i++){
            string t;
            for(int j =0; j<n; j++){
                t+=to_string(grid[j][i])+'#';
            }
            cols[t]++;
        }

        int cnt = 0;
        for(auto it: rows){
            if(cols.find(it.first)!=cols.end()){
                cnt+=(it.second*cols[it.first]);
            }
        }

        return cnt;
    }
};