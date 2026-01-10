class Solution {
public:
    /*
    recursion
    int helper(string a, string b){
        if(a.length() == 0){
            int sum = 0;
            for(char ch: b){
                sum += ch;
            }
            return sum;
        }
        if(b.length() == 0){
            int sum = 0;
            for(char ch: a){
                sum += ch;
            }
            return sum;
        }

        int s1 = 0;
        int s2 = 0;
        if(a[0]!=b[0]){
            s1 = a[0] + helper(a.substr(1), b);
            s2 = b[0] + helper(a, b.substr(1));
            return min(s1,s2);
        }
        else{
            return helper(a.substr(1), b.substr(1));
        }
    }
    */

    // memoization
    
public:
    int helper(string& s1, string& s2, vector<vector<int>>& dp, int i, int j) {
        if (i == s1.length()) {
            int sum = 0;
            for (int k = j; k < s2.length(); k++) sum += s2[k];
            return sum;
        }

        if (j == s2.length()) {
            int sum = 0;
            for (int k = i; k < s1.length(); k++) sum += s1[k];
            return sum;
        }

        if (dp[i][j] != -1) return dp[i][j];

        if (s1[i] == s2[j]) {
            dp[i][j] = helper(s1, s2, dp, i + 1, j + 1);
        } else {
            dp[i][j] = min(
                s1[i] + helper(s1, s2, dp, i + 1, j),
                s2[j] + helper(s1, s2, dp, i, j + 1)
            );
        }

        return dp[i][j];
    }

    int minimumDeleteSum(string s1, string s2) {
        vector<vector<int>> dp(s1.length(), vector<int>(s2.length(), -1));
        return helper(s1, s2, dp, 0, 0);
    }
};
