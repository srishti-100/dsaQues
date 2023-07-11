/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    void helper(TreeNode* root, int hd, int vd, map<int,vector<pair<int,int>>>& mp){
        if(root == NULL) return;

       mp[hd].push_back({vd,root->val});
       helper(root->left, hd-1, vd+1, mp);
       helper(root->right, hd+1, vd+1, mp); 
    }
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int,vector<pair<int,int>>> mp;
        helper(root,0,0,mp);

        vector<vector<int>> ans;
        for(auto it: mp){
            vector<int> v;
            sort(it.second.begin(), it.second.end());
            for(auto x: it.second){
                v.push_back(x.second);
            }
            ans.push_back(v);
        }

        return ans;
    }
};