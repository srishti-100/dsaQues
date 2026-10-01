class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        queue<pair<int,int>> q;

        vector<vector<int>> visited(n,vector<int>(m,-1));

        for(int i =0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(grid[i][j]==2){
                    q.push({i,j});
                    visited[i][j] = 1;
                }
            }
        }

        vector<vector<int>> dr = {{-1,0},{1,0},{0,-1},{0,1}};
        int ans = -1;
        while(!q.empty()){
            int s = q.size();
            ans++;
            for(int i =0; i<s; i++){
                pair<int,int> p = q.front();
                int r = p.first;
                int c = p.second;
                q.pop();
                
                for(int j =0; j<4; j++){
                    int nr = r + dr[j][0];
                    int nc = c + dr[j][1];

                    if(nr >= 0 && nc >= 0 && nr<n && nc <m && visited[nr][nc]==-1 && grid[nr][nc]==1){
                       
                        grid[nr][nc] = 2;
                        q.push({nr,nc});
                        visited[nr][nc] = 1;
                    }
                }
            }
        }

        for(int i =0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(grid[i][j]==1){
                    return -1;
                }
            }
        }

        return max(ans,0);

    }
};