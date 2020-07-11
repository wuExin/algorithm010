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
    bool isBalanced(TreeNode* root) {
        int height;
        return bfs(root, height);
    }
    bool bfs(TreeNode* root,int& height) {
        if(root == NULL) {
            height = -1;
            return true;
        }
        int leftHeight, rightHeight;
        bool left  = bfs(root->left,leftHeight);
        bool right = bfs(root->right,rightHeight);
        if(left && right && abs(leftHeight - rightHeight) < 2) {
            height = max(leftHeight,rightHeight) + 1;
            return true;
        }
        return false;
    }
};