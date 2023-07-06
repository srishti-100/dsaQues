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
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root == NULL) return ans;
        queue<TreeNode*> q;
        q.push(root);
        bool flag = 1;
        while(!q.empty()){
            int s = q.size();
            vector<int> v(s);
            for(int i =0; i<s; i++){
                TreeNode* f = q.front();
                q.pop();
                if(flag == 1){
                    v[i]=f->val;
                }
                if(flag == 0)
                    v[s-1-i] = f->val;

                if(f->left!=NULL) q.push(f->left);
                if(f->right!=NULL) q.push(f->right);
            }
            flag = !flag;
            ans.push_back(v);
        }

        return ans;
    }
};