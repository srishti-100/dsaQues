class Solution {
public:
    int helper(int i, int j, string s, string t, vector<vector<int>>& dp){
        if(i==s.length() && j==t.length())
            return 0;

        if(i!=s.length() && j==t.length())
            return 0;
        
        if(i==s.length() && j!=t.length()){
            return t.length()-j;
        }

        if(dp[i][j]!=-1){
            return dp[i][j];
        }

        if(s[i]==t[j]){
            return  dp[i][j] = helper(i+1,j+1,s,t,dp);
        }
        
            return dp[i][j] = helper(i+1,j,s,t,dp);
        
    }
    int appendCharacters(string s, string t) {
        int n = s.length();
        int m = t.length();
        // vector<vector<int>> dp(n,vector<int>(m,-1));
        // return helper(0,0,s,t,dp);

        int i = 0, j= 0;

        while(i<n && j<m){
            if(s[i]==t[j]){
                j++;
            }
            i++;
        }
        return m - j;
    }
};