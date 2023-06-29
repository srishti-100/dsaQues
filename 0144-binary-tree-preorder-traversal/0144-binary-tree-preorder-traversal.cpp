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
    //Method 1
    /*
private:
    void helper(TreeNode* root, vector<int>& ans){
        if(root==NULL) return;
        ans.push_back(root->val);
        helper(root->left, ans);
        helper(root->right, ans);
    }
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        helper(root,ans);
        return ans;
    }
    */
    public:
    vector<int> preorderTraversal(TreeNode* root) {       
        vector<int> ans;
        if(root == NULL) return ans;
        stack<TreeNode*> s;
        s.push(root);

        while(!s.empty()){
            TreeNode* t = s.top();
            ans.push_back(t->val);
            s.pop();
            if(t->right!=NULL) s.push(t->right);
            if(t->left!=NULL) s.push(t->left);
        }
        return ans;
    }
};