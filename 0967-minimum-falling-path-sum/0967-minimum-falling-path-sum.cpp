class Solution {
public:
/*
    int helper(int r, int c, int rows, int cols, vector<vector<int>>& dp, vector<vector<int>>& mat){
        if(c<0 || c == cols){
            return INT_MAX;
        }
        if(r==rows-1) return mat[r][c];

        if(dp[r][c]!=-1) return dp[r][c];

        int s1 = helper(r+1,c-1,rows,cols,dp,mat);
        int s2 = helper(r+1,c,rows,cols,dp,mat);
        int s3 = helper(r+1,c+1,rows,cols,dp,mat);

        dp[r][c] = min(s1,min(s2,s3)) + mat[r][c];

        return dp[r][c];

    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        vector<vector<int>> dp(rows,vector<int>(cols,-1));
        int maxi = INT_MAX;
    
        for(int j=0; j<cols;j++){
            int ans = helper(0,j,rows,cols,dp,matrix);
            maxi = min(maxi,ans);
        }
        return maxi;
    }
    */
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        vector<vector<int>> dp(rows,vector<int>(cols,0));
        int mini = INT_MAX;
        for(int i =0; i<cols; i++){
            dp[rows-1][i] = matrix[rows-1][i];
        }

        for(int i = rows-2; i>=0; i--){
            for(int j = 0; j<cols; j++){
                if(j>0 && j<=cols-2){
                    mini = min(dp[i+1][j-1],min(dp[i+1][j],dp[i+1][j+1]));
                    dp[i][j]=mini+matrix[i][j];
                }
                else if(j==0){
                    mini = min(dp[i+1][j],dp[i+1][j+1]);
                    dp[i][j]=mini+matrix[i][j];
                }
                else if(j>cols-2){
                    mini = min(dp[i+1][j-1],dp[i+1][j]);
                    dp[i][j]=mini+matrix[i][j];
                }
            }
        }
        int minVal = INT_MAX;

        for(int i =0; i<cols; i++){
            minVal = min(minVal,dp[0][i]);
        }

        return minVal;

    }
};