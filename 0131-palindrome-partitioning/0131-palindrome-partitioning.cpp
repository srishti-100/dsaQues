class Solution {
public:
    bool isPallindrome(const string& s){
        int n = s.size();
        if(n<=1) return true;
        int l = 0;
        int r = n-1;
        while(l<r){
            if(s[l] != s[r]) return false;
            l++; r--;
        }
        return true;
    }
    void helper(string s, int idx, vector<string> curr,int& n, vector<vector<string>>& ans){
        if(idx == n){
            ans.push_back(curr);
            return;
        }

        for(int i = idx; i<s.size(); i++){
            string temp = s.substr(idx, i-idx+1);
            if(isPallindrome(temp)){
                curr.push_back(temp);
                helper(s, i+1, curr, n, ans);
                curr.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> curr;
        int n = s.size();
        helper(s,0, curr, n, ans);
        return ans;
    }
};