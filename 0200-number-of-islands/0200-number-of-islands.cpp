class Solution {
private:
    void helper(int r, int c, int rows, int cols,vector<vector<char>>& grid, vector<vector<bool>>& visited ){
        if(r<0 || c<0 || r>=rows || c>=cols ||grid[r][c]=='0'|| visited[r][c]){
            return;
        }
        visited[r][c]=true;
        
            helper(r-1,c,rows,cols,grid,visited);
        
       
            helper(r+1,c,rows,cols,grid,visited);
        
        
            helper(r,c-1,rows,cols,grid,visited);
        
        
            helper(r,c+1,rows,cols,grid,visited);
        
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>> visited(n,vector<bool>(m,false));
        int count = 0;
        for(int i =0; i<n; i++){
            for(int j =0; j<m; j++){
                if(!visited[i][j] && grid[i][j]=='1'){
                    
                        count++;
                        helper(i,j,n,m,grid,visited);
                    
                }
            }
        }

        return count;
    
    }
};