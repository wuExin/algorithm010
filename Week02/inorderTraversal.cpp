class Solution {
vector<int> ret;
public:
    vector<int> inorderTraversal(TreeNode* root) {   
            if (root == NULL) {
                return ret;
            }
            inorderTraversal(root->left);
            ret.push_back(root->val);
            inorderTraversal(root->right);
            return ret;
    }
};