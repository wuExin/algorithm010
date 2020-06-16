class Solution {
    vector<int> ret;
public:
    vector<int> preorderTraversal(TreeNode* root) {
        if (root == NULL) {
            return ret;
        }
        ret.push_back(root->val);
        preorderTraversal(root->left);
        preorderTraversal(root->right);
        return ret;
    }
};

