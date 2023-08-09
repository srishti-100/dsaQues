class Solution {
private:
    bool helper(int i, int j, string s, string t, vector<vector<int>>& dp){
        if(i<0 && j<0) return 1;
        if(j<0 && i>=0) return 0;
        if(i<0 && j>=0){
            for(int k = j; k>=0; k--){
                if(t[k]!='*'){
                    return 0;
                }
            }
            return 1;
        }
        if(dp[i][j]!=-1) return dp[i][j]==1;
        bool result =false;
        if(s[i]==t[j] || t[j]=='?'){
            result = helper(i-1,j-1,s,t,dp);
        }
        else if(t[j]=='*'){
                result = helper(i,j-1,s,t,dp) || helper(i-1,j,s,t,dp);
            }
        else{
            result = 0;
        }
        dp[i][j] = result?1:0;
        return result;
    }
public:
    // bool isMatch(string s, string t) {
    //     int n = s.length();
    //     int m = t.length();
    //     vector<vector<int>> dp(n,vector<int>(m,-1));
    //     return helper(n-1,m-1,s,t,dp)==0?false:true;
    // }

    bool isMatch(string s, string t) {
        int n = s.length();
        int m = t.length();
        vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
        dp[0][0]=1;
        for(int i =1; i<=n; i++){
            dp[i][0]=0;
        }
        for(int i =1; i<=m;i++){
            if(dp[0][i-1]==1 && t[i-1]=='*'){
                dp[0][i]=1;
            }
            else{
                dp[0][i]=0;
            }
            
        }

        for(int i = 1; i<=n; i++){
            for(int j =1; j<=m; j++){
                bool result =false;
                if(s[i-1]==t[j-1] || t[j-1]=='?'){
                    result = dp[i-1][j-1];
                }
                else if(t[j-1]=='*'){
                        result = dp[i][j-1] || dp[i-1][j];
                    }
                else{
                    result = 0;
                }
                dp[i][j] = result?1:0;
            }
        }

        return dp[n][m];

    }


};