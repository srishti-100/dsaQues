class Solution {
public:
    void helper(int n,vector<bool>& visited, string perm, vector<string>& ans){
        if(perm.length()==n){
            ans.push_back(perm);
            return;
        }

        for(int i =1; i<=n; i++){
            if(!visited[i]){
                perm.push_back(i + '0');
                visited[i] = true;
                helper(n,visited, perm, ans);
                perm.pop_back();
                visited[i] = false;
            }
        }
    }

    string getPermutation(int n, int k) {
        vector<int>nums;
        for(int i = 1; i<=n; i++){
            nums.push_back(i);
        }

        vector<bool> visited(n+1, false);
        vector<string> ans;

        helper(n, visited, "", ans);

        return ans[k-1];

    }
};