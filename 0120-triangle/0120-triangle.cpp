class Solution {
public:
    int mini = INT_MAX;
    int helper(int r,int c, int rows, vector<vector<int>>& dp,vector<vector<int>>& mat){
        if(c==rows){
            return INT_MAX;
        }
        if(r == rows-1) return mat[r][c];
        if(dp[r][c]!=-1) return dp[r][c];
        int s1 = helper(r+1,c,rows,dp,mat);
        int s2 = helper(r+1,c+1,rows,dp,mat);
        dp[r][c] = min(s1,s2) + mat[r][c];
        return dp[r][c];

    }
    int minimumTotal(vector<vector<int>>& triangle) {
        
        int rows = triangle.size();
        vector<vector<int>> dp;
        for(int i =0; i<rows; i++){
            vector<int>d(i+1,-1);
            dp.push_back(d);
        }
        return helper(0,0,rows,dp,triangle);
    }
};