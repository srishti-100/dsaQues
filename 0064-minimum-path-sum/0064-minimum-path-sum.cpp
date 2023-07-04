// class Solution {
//     int helper(int r, int c, int rows, int cols,vector< vector< int> > &mat, vector<vector<int>>& dp){
// 	if(r<0 || r==rows|| c<0 || c==cols){
// 		return INT_MAX;
// 	}
	
// 	if(r == rows-1 && c ==cols-1){
// 		return mat[r][c];
// 	}

// 	if(dp[r][c]!=-1) return dp[r][c];
    
// 	int ans1 = helper(r+1,c,rows,cols,mat,dp);
// 	int ans2 = helper(r,c+1,rows,cols,mat,dp);

// 	dp[r][c] = min(ans1,ans2)+mat[r][c];

// 	return dp[r][c];

// }

// public:
//     int minPathSum(vector<vector<int>>& mat) {
//         int m = mat.size();
// 				int n = mat[0].size();
//         vector<vector<int>> dp(m,vector<int>(n,-1));
		
// 	return helper(0,0,m,n,mat,dp);
//     }
// };

class Solution {
    public:
    int minPathSum(vector<vector<int>>& mat) {
        int rows = mat.size();
        int cols = mat[0].size();
        vector<vector<int>> dp(rows,vector<int>(cols,-1));

        dp[rows-1][cols-1] = mat[rows-1][cols-1];

        for(int i = rows-1; i>=0; i--){
            for(int j = cols-1; j>=0; j--){
                if(dp[i][j]!=-1) continue;
                
                if(i+1 >=rows){
                    dp[i][j]= dp[i][j+1] + mat[i][j];
                }

                else if(j+1 >=cols){
                    dp[i][j]= dp[i+1][j] + mat[i][j];
                }
                else{
                    dp[i][j]=min(dp[i][j+1],dp[i+1][j]) + mat[i][j];
                }

            }

        }

        return dp[0][0];

    }
};