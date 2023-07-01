class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int minute = 0;

        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> visited(n,vector<int>(m,0));

        queue<pair<int,int>> q;

        for(int i =0; i<n; i++){
            for(int j = 0;j<m; j++){
                if(grid[i][j]==2){
                    q.push({i,j});
                    visited[i][j]=2;
                }
            }
        }

        vector<int> rd{-1,0,1,0};
        vector<int> cd{0,1,0,-1};

        while(!q.empty()){
            
            int s = q.size();

            for(int i=0; i<s; i++){
                int r = q.front().first;
                int c = q.front().second;

                q.pop();

                for(int j = 0; j<4; j++){
                    int nr = r+ rd[j];
                    int nc = c+cd[j];

                    if(nr>=0 && nr<n && nc>=0 && nc<m&& grid[nr][nc]==1 && visited[nr][nc]==0){
                        q.push({nr,nc});
                        visited[nr][nc]=2;
                    }
                }

            }
            if(!q.empty())minute++;
        }

        for(int i =0; i<n; i++){
            for(int j =0;j<m; j++){
                if(visited[i][j]==0 && grid[i][j]==1) return -1;
            }
        }

        return minute;
    }
};