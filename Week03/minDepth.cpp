class Solution {
public:
    int minDepth(TreeNode* root) {
         if (root == NULL) {
             return 0;
         }
         if (root->left == NULL && root->right == NULL) {
             return 1;
         }  
         int minLeft  = minDepth(root->left);
         int minRight = minDepth(root->right);
         int depth;
         if (root->left !=NULL || root->right != NULL) {
             depth = minLeft + minRight + 1;
         }
         if (root->left !=NULL && root->right != NULL) {
             depth = minLeft <= minRight ? minLeft + 1 : minRight + 1;
         }
         return depth;
    }
};