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
    int res = 0;
    int diameterOfBinaryTree(TreeNode* root) {
        if(root == NULL) {
            return res;
        }
        dfs(root);
        return res - 1;
    }
    int dfs(TreeNode* node) {
        if(node == NULL) {
            return 0;
        }
        int leftCount  = dfs(node->left);
        int rightCount = dfs(node->right);
        res = max(res,leftCount + rightCount + 1);
        return max(leftCount,rightCount) + 1;
    }
};