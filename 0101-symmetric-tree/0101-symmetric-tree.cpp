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
    bool helper(TreeNode* l, TreeNode* r){
        if(l==NULL && r == NULL) return true;
        if(l==NULL^r==NULL) return false;
        if(l->val!=r->val) return false;

        bool ans1 = helper(l->left,r->right);
        bool ans2 = helper(l->right,r->left);
        return ans1&&ans2;
    }

public:
    bool isSymmetric(TreeNode* root) {
        if(root == NULL) return true;

        return helper(root->left,root->right);
    }
};