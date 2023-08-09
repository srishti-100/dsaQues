class Solution {
public:
    int numDistinct(string a, string b) {
        int n = a.length();
        int m = b.length();

        // vector<vector<double>> dp(n+1,vector<double>(m+1,0));
        vector<double> prev(m+1,0);
        vector<double> curr(m+1,0);
        // for(int i =0; i<=n; i++){
        //     dp[i][0] = 1;
        // }
        prev[0]=curr[0]=1;

        for(int i =1; i<=n; i++){
            for(int j = 1; j<=m; j++){
                if(a[i-1]==b[j-1]){
                    curr[j]=prev[j]+prev[j-1];
                }
                else{
                    curr[j]=prev[j];
                }
            }
            prev=curr;
        }

        return (int)prev[m];
    }
};