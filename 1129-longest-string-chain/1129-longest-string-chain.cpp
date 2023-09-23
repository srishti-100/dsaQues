class Solution {
public:
    static bool cmp(string a, string b){
        return a.length()<b.length();
    }
    bool cntCheck(string a, string b){
        if(a.length()==b.length()) return false;
        if(a.length()+1!=b.length()) return false;
        if(a.length()==0 ^b.length()==0) return false;

        int i =0;
        int j =0;
        int n = a.length();
        int m = b.length();
        int cnt = 0;

        while(i<n && j<m){
            if(a[i]==b[j]) {
                i++;
                j++;
            }
            else {
                if(cnt==0){
                    j++;
                    cnt++;
                }
                else{
                    return false;
                }
            }
        }
        return true;
    }
    
    /*
    int helper(int idx, vector<string>& words, int prev_idx, int n, vector<vector<int>>& dp){
        if(idx==n) return 0;
        if(dp[idx][prev_idx+1]!=-1) return dp[idx][prev_idx+1];
        int notPick = helper(idx+1,words,prev_idx,n, dp);

        int pick = 0;
        if(prev_idx==-1 || cntCheck(words[prev_idx],words[idx])){
            pick=1+helper(idx+1,words, idx,n, dp);
        }

        return dp[idx][prev_idx+1] = max(pick,notPick);
    }


    int longestStrChain(vector<string>& words) {
        sort(words.begin(),words.end(),cmp);
        int n = words.size();
        vector<vector<int>> dp(n,vector<int>(n+1,-1));
        return helper(0,words,-1, n, dp);

    }
    */

    int longestStrChain(vector<string>& words) {
        sort(words.begin(),words.end(),cmp);
        int n = words.size();
        vector<vector<int>> dp(n+1,vector<int>(n+1,0));
        
        for(int i = n-1; i>=0; i--){

            for(int j = i-1; j>=-1; j--){
                int notPick = dp[i+1][j+1];

                int pick = 0;
                if(j==-1 || cntCheck(words[j],words[i])){
                    pick=1+dp[i+1][i+1];
                }

                dp[i][j+1] = max(pick,notPick);
            }
        }

        return dp[0][0];
    }

};