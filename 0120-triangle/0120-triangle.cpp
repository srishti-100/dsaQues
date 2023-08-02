class Solution {
private:
    int helper(int r, int c, int n, vector<vector<int>>& arr,vector<vector<int>>& dp){
        if(r<0 || r>=n || c<0 || c>=r+1){
            return INT_MAX;
        }
        if(dp[r][c]!=-1) return dp[r][c];
        
        int s1 = helper(r+1,c,n,arr,dp);
        int s2 = helper(r+1,c+1,n,arr,dp);

        if(min(s1,s2)==INT_MAX){
            dp[r][c] =  arr[r][c];
        }
        else dp[r][c] = min(s1,s2)+arr[r][c];
        return dp[r][c];
    }
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        int cols = triangle[n-1].size();
        vector<vector<int>> dp(n,vector<int>(cols,-1));
        return helper(0,0,n,triangle,dp);
    }
};