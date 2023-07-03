// class Solution {
// public:
//     vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
//         int m = mat.size();
//         int n = mat[0].size();
//         vector<vector<int>> ans(m, vector<int>(n,0)); 
//         vector<vector<int>> visited(m, vector<int>(n,0)); 
//                      // r  c d
//         queue<pair<pair<int,int>, int>> q;

//         for(int i =0; i<m; i++){
//             for(int j = 0; j<n; j++){
//                 
//                 if(mat[i][j]==0){ 
//                     q.push({{i,j},0});
//                     visited[i][j]=1;
//                 }
//                 else{
//                     visited[i][j]=0;
//                 }
                
//             }
//         }

//         vector<int> delRow{-1,0,1,0};
//         vector<int> delCol{0,1,0,-1};
//         while(!q.empty()){
            
//             int r = q.front().first.first;
//             int c = q.front().first.second;
//             int dist = q.front().second;
//             q.pop();

//             ans[r][c]=dist;
                
//             for(int i =0; i<4; i++){
//                 int nr = r+delRow[i];
//                 int nc = c+delCol[i];
//                 if(nr>=0 && nr<m && nc>=0 && nc<n && visited[nr][nc]==0){
                        
//                     visited[nr][nc]=1;
//                     q.push({{nr,nr},dist+1});
                        
//                 }
//             }

//         }

//         return ans;
//     }
// };

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& grid) {
        
	    int n = grid.size(); 
	    int m = grid[0].size(); 
	    // visited and distance matrix
	    vector<vector<int>> vis(n, vector<int>(m, 0)); 
	    vector<vector<int>> dist(n, vector<int>(m, 0)); 
	    // <coordinates, steps>
	    queue<pair<pair<int,int>, int>> q; 
	    // traverse the matrix
	    for(int i = 0;i<n;i++) {
	        for(int j = 0;j<m;j++) {
	            // start BFS if cell contains 1
	            if(grid[i][j] == 0) {
	                q.push({{i,j}, 0}); 
	                vis[i][j] = 1; 
	            }
	            else {
	                // mark unvisited 
	                vis[i][j] = 0; 
	            }
	        }
	    }
	    
	    int delrow[] = {-1, 0, +1, 0}; 
	    int delcol[] = {0, +1, 0, -1}; 
	    
	    // traverse till queue becomes empty
	    while(!q.empty()) {
	        int row = q.front().first.first; 
	        int col = q.front().first.second; 
	        int steps = q.front().second; 
	        q.pop(); 
	        dist[row][col] = steps; 
	        // for all 4 neighbours
	        for(int i = 0;i<4;i++) {
	            int nrow = row + delrow[i]; 
	            int ncol = col + delcol[i]; 
	            // check for valid unvisited cell
	            if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m 
	            && vis[nrow][ncol] == 0) {
	                vis[nrow][ncol] = 1; 
	                q.push({{nrow, ncol}, steps+1});  
	            }
	        }
	    }
	    // return distance matrix
	    return dist; 
	}
};