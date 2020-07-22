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
    vector<TreeNode*> generateTrees(int start,int end) {
        if(start > end) return {nullptr};
        vector<TreeNode*> res;
        for(int i = start;i <= end; i++) {
            vector<TreeNode*> leftTree  = generateTrees(start,i-1);
            vector<TreeNode*> rightTree = generateTrees(i+1,end);
            for(auto& left : leftTree) {
                for(auto& right : rightTree) {
                    TreeNode* currTree = new TreeNode(i);
                    currTree->left  = left;
                    currTree->right = right;
                    res.emplace_back(currTree);
                }
            }
        }
        return res;
    }

    vector<TreeNode*> generateTrees(int n) {
        if(n < 1) return {};
        return generateTrees(1,n);
    }
};