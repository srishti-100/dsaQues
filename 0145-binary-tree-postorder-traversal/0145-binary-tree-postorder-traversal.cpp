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
    /*
private:
    void helper(TreeNode* root, vector<int>& ans){
        if(root==NULL) return;
        helper(root->left, ans);
        helper(root->right, ans);
        ans.push_back(root->val);

    }
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        helper(root, ans);
        return ans;
    }
    */

    public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        if(root == NULL) return ans;
        stack<TreeNode*> s1;
        stack<TreeNode*> s2;

        s1.push(root);

        while(!s1.empty()){
            TreeNode* t = s1.top();
            s1.pop();
            
            if(t->left!=NULL) s1.push(t->left);
            if(t->right!=NULL) s1.push(t->right);

            s2.push(t);
        }

        while(!s2.empty()){
            ans.push_back(s2.top()->val);
            s2.pop();
        }
        return ans;
    }
};