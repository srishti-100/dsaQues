class Solution {
    /*
private:
    bool checkPallindrome(string s){
        int i =0;
        int j = s.length()-1;
        while(i<j){
            if(s[i]!=s[j]) return false;
            i++;
            j--;
        }
        return true;
    }

    void helper(int i, int n, string& s, string t, int& lmax){
        if(i==n){
            if(checkPallindrome(t)){
                if(t.length()>lmax){
                    lmax = t.length();
                }
                return;
            }
            return;
        }

        helper(i+1,n,s,t+s[i],lmax);
        helper(i+1,n,s,t,lmax);
    }
public:
    int longestPalindromeSubseq(string s) {
        string t="";
        int lmax = INT_MIN;

        helper(0,s.length(),s,t,lmax);
        if(lmax==INT_MIN) return 0;
        return lmax;
    }
    */
    private:
    int helper(int i, int j, int n, string& s, vector<vector<int>>& dp){
        if(i==n-1 || j==0) return 1;
        if(i==j){
            return 1;
        }
        if (s[i] == s[j] && i + 1 == j)
            return 2;
        if(dp[i][j]!=-1) return dp[i][j];
        if(s[i]==s[j]){
            dp[i][j]= 2 + helper(i+1,j-1,n,s,dp);
        }
        else
        dp[i][j]= max(helper(i+1,j,n,s,dp), helper(i,j-1,n,s,dp));

        return dp[i][j];
        
    }


    public:
    int longestPalindromeSubseq(string s) {
        int i =0;
        int n = s.length();
        int j = n-1;
        vector<vector<int>> dp(n,vector<int>(n,-1));
        return helper(i,j,n,s,dp);
    }
};