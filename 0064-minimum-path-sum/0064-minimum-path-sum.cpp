class Solution {
    int helper(int r, int c, int rows, int cols,vector< vector< int> > &mat, vector<vector<int>>& dp){
	if(r<0 || r==rows|| c<0 || c==cols){
		return INT_MAX;
	}
	
	if(r == rows-1 && c ==cols-1){
		return mat[r][c];
	}

	if(dp[r][c]!=-1) return dp[r][c];
    
	int ans1 = helper(r+1,c,rows,cols,mat,dp);
	int ans2 = helper(r,c+1,rows,cols,mat,dp);

	dp[r][c] = min(ans1,ans2)+mat[r][c];

	return dp[r][c];

}

public:
    int minPathSum(vector<vector<int>>& mat) {
        int m = mat.size();
				int n = mat[0].size();
        vector<vector<int>> dp(m,vector<int>(n,-1));
		
	return helper(0,0,m,n,mat,dp);
    }
};