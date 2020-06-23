class Solution {
public:
    bool isValidBST(TreeNode* root) {
        return fun(root,LONG_MIN,LONG_MAX);
    }
    
    bool fun(TreeNode* root, long min,long max) {
        //terminator
        if (root == NULL) {
            //process result
            return true;
        }
        // current process logic
        if(root->val >= max || root->val <= min) {
            return false;
        }
        // drill down
        return fun(root->left, min, root->val) && fun(root->right,root->val, max);
    }
};