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
    vector<int> res;

    vector<int> largestValues(TreeNode* root) {
        if (root == NULL) {
            return res;
        }
        bfs(root);
        return res;
    }
    void bfs(TreeNode* root) {
        queue<TreeNode*> qe;
        qe.push(root);
        while(!qe.empty()) {
            int size = qe.size();
            long max =  LONG_MIN;
            for (int i = 0;i<size;i++) {
                TreeNode* front = qe.front();
                qe.pop();
                if (max < front->val) {
                    max = front->val;
                }
                if (front->left != NULL) {
                    qe.push(front->left);
                }
                 if (front->right != NULL) {
                    qe.push(front->right);
                }               
            }
            res.push_back(max);
        }
    }
};