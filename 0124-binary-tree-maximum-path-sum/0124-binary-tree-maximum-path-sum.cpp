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
    int helper(TreeNode* root, int& maxSum){
        if(root == NULL) return 0;

        int s1 = helper(root->left,maxSum);
        int s2 = helper(root->right, maxSum);
        if(s1<0) s1=0;
        if(s2<0) s2 = 0;

        maxSum = max(maxSum,s1+s2+root->val);
        return max(s1,s2)+root->val;
    }
public:
    int maxPathSum(TreeNode* root) {
        int maxSum = INT_MIN;
        int res = helper(root,maxSum);

        return max(res,maxSum);
    }
};