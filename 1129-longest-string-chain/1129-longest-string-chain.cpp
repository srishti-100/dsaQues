class Solution {
private:
    bool eraseString(string str1,string str2){
        if(str1.empty() || str2.empty()) return false;
        if(str1.length()+1 !=str2.length()) return false;
        for(int i =0; i<str2.length(); i++){
            string modifiedStr = str2;
            modifiedStr.erase(modifiedStr.begin() + i);
            if(modifiedStr==str1){
                return true;
            }
        }
        return false;

    }
    



    int helper(int idx, int n, int prev_idx, vector<string>& words, vector<vector<int>>& dp){
        if(idx==n) return 0;
        if(dp[idx][prev_idx+1]!=-1) return dp[idx][prev_idx+1];
        int nt = helper(idx+1, n, prev_idx, words,dp);
        int t = 0;
    
        if( prev_idx==-1  || eraseString(words[prev_idx],words[idx])){
            t = 1+helper(idx+1,n,idx,words,dp);
        }
        return dp[idx][prev_idx+1]=max(nt,t);
    }


public:
    static bool cmp(string s1,string s2){
        return s1.length()<s2.length();
    }

    /*
    int longestStrChain(vector<string>& words) {
        sort(words.begin(), words.end(),cmp);
        int n = words.size();
        // vector<vector<int>> dp(n+1,vector<int>(n+1,0));
        vector<int> curr(n+1,0);
        vector<int> last(n+1,0);

        for(int i = n-1; i>=0; i--){
            for(int j = i-1; j>=-1; j--){
                int nt = last[j+1];
                int t = 0;
            
                if( j==-1  || eraseString(words[j],words[i])){
                    t = 1+last[i+1];
                }
                curr[j+1]=max(nt,t);
            }
            last = curr;
        }
        return last[0];
    }
    */

    int longestStrChain(vector<string>& words) {
        int n = words.size();
        sort(words.begin(),words.end(),cmp);
        vector<int> dp(n,1);
        int maxi = 1;

        for(int i =1; i<n; i++){
             for(int j = 0; j<i; j++){
                 if(eraseString(words[j],words[i])){
                     dp[i] = max(dp[i],dp[j]+1);
                 }
             }
             maxi = max(maxi,dp[i]);
        }
        return maxi;
    }

};