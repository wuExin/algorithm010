class Solution {
public:
    vector<int> ret;
    vector<int> preorder(Node* root) {
        if (root == NULL) {
            return ret;
        }
        ret.push_back(root->val);
        for (auto& node : root->children) {
            preorder(node);
        }
        return ret;
    }
};