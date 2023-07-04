class Solution {
public:
    void helper(int r , int c, int rows, int cols ,vector<vector<char>>& grid, vector<vector<int>>& visited, int delRow[] , int delCol[]){
        visited[r][c]=0;

        for(int i =0; i<4; i++){
            int nr = r+delRow[i];
            int nc = c+delCol[i];

            if(nr>=0 && nc>=0 && nr<rows && nc<cols  && grid[nr][nc]=='O' && visited[nr][nc]==-1){
                helper(nr,nc,rows,cols,grid,visited,delRow,delCol);
            }
        }
    }


    void solve(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> visited(n,vector<int>(m,-1));
        int delRow[]={-1,0,1,0};
        int delCol[]={0,1,0,-1};

        for(int i =0; i<m ; i++){
            if(grid[0][i]=='O' && visited[0][i]==-1){
                helper(0,i,n,m,grid,visited,delRow, delCol);
            }
            if(grid[n-1][i]=='O' && visited[n-1][i]==-1){
                helper(n-1,i,n,m,grid,visited,delRow, delCol);
            }
        }

        for(int i =0; i<n ; i++){
            if(grid[i][m-1]=='O' && visited[i][m-1]==-1){
                helper(i,m-1,n,m,grid,visited,delRow, delCol);
            }
            if(grid[i][0]=='O' && visited[i][0]==-1){
                helper(i,0,n,m,grid,visited,delRow, delCol);
            }
        }

        

        for(int i =0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(grid[i][j]=='O' && visited[i][j]==-1){
                    grid[i][j]='X';
                }
            }
        }
    }
};