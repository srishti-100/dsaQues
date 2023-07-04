/*

class Solution {
public:
    void helper(int r , int c, int rows, int cols ,vector<vector<int>>& grid, vector<vector<int>>& visited, int delRow[] , int delCol[]){
        visited[r][c]=0;

        for(int i =0; i<4; i++){
            int nr = r+delRow[i];
            int nc = c+delCol[i];

            if(nr>=0 && nc>=0 && nr<rows && nc<cols  && grid[nr][nc]==1 && visited[nr][nc]==-1){
                helper(nr,nc,rows,cols,grid,visited,delRow,delCol);
            }
        }
    }


    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> visited(n,vector<int>(m,-1));
        int delRow[]={-1,0,1,0};
        int delCol[]={0,1,0,-1};

        for(int i =0; i<m ; i++){
            if(grid[0][i]==1 && visited[0][i]==-1){
                helper(0,i,n,m,grid,visited,delRow, delCol);
            }
            if(grid[n-1][i]==1 && visited[n-1][i]==-1){
                helper(n-1,i,n,m,grid,visited,delRow, delCol);
            }
        }

        for(int i =0; i<n ; i++){
            if(grid[i][m-1]==1 && visited[i][m-1]==-1){
                helper(i,m-1,n,m,grid,visited,delRow, delCol);
            }

            if(grid[i][0]==1 && visited[i][0]==-1){
                helper(i,0,n,m,grid,visited,delRow, delCol);
            }
        }

        
        int count = 0;
        for(int i =0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(grid[i][j]==1 && visited[i][j]==-1){
                    count++;
                }
            }
        }
        return count;
    }
};

*/

class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {

        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> visited(n,vector<int>(m,-1));
        queue<pair<int,int>> q;

        for(int i =0; i<m ; i++){
            if(grid[0][i]==1 && visited[0][i]==-1){
                q.push({0,i});
                visited[0][i]=0;
            }
            if(grid[n-1][i]==1 && visited[n-1][i]==-1){
                q.push({n-1,i});
                visited[n-1][i]=0;
            }
        }

        for(int i =0; i<n ; i++){
            if(grid[i][m-1]==1 && visited[i][m-1]==-1){
                q.push({i,m-1});
                visited[i][m-1]=0;
            }

            if(grid[i][0]==1 && visited[i][0]==-1){
                q.push({i,0});
                visited[i][0]=0;
            }
        }

        int delRow[]={-1,0,1,0};
        int delCol[]={0,1,0,-1};

        while(!q.empty()){
            int r = q.front().first;
            int c = q.front().second;
            q.pop();
            for(int i = 0; i<4; i++){
                int nr = r + delRow[i];
                int nc = c + delCol[i];

                if(nr>=0 && nc>=0 && nr<n && nc<m && visited[nr][nc]==-1 && grid[nr][nc]==1){
                    visited[nr][nc]=0;
                    q.push({nr,nc});
                }
            }
        }

        int count = 0;
        for(int i =0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(grid[i][j]==1 && visited[i][j]==-1){
                    count++;
                }
            }
        }
        return count;

    }
};