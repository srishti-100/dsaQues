class Solution {
public:
    int minDistance(string s, string t) {
        int n = s.length();
        int m = t.length();
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        for(int i =0; i<=n; i++){
            dp[i][0]=0;
        }
        for(int i =0; i<=m; i++){
            dp[0][i]=0;
        }
        
        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                if(s[i-1]==t[j-1]){
                    dp[i][j]=1+dp[i-1][j-1];
                }
                else{
                    dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
                }
            }
        }
       int len = dp[n][m];
       if(len==n){
           return m-len;
       }
       else if(len==m){
           return n-len;
       }
       else{
           return (n-len)+(m-len);
       }
       return 0;
    }
};