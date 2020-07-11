/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
       return dfs(root,root);
    }
    bool dfs(TreeNode* node1,TreeNode* node2) {
        if(node1 == NULL && node2 == NULL) {
            return true;
        }
        if(node1 == NULL || node2 == NULL) {
            return false;
        }
        return node1->val == node2->val && dfs(node1->left,node2->right) && dfs(node1->right,node2->left);
    }
};