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
    TreeNode* constructFromPrePost(vector<int>& pre, vector<int>& post) {    
        if(pre.size() == 0 && post.size() == 0) {
            return NULL;
        }
        TreeNode* root = new TreeNode(pre[0]);
        if(pre.size() == 1) {
            return root;
        }
        int rootVal = pre[1];
        int L = 0;
        for(int i = 0;i<post.size();i++) {
            if(rootVal == post[i]) {
                L = i + 1;
                break;
            }
        }
        vector<int> leftPre(pre.begin()+1, pre.begin()+L+1);
        vector<int> rightPre(pre.begin()+L+1, pre.end());
        vector<int> leftPost(post.begin(), post.begin()+L);
        vector<int> rightPost(post.begin()+L, post.end()-1);

        root->left  = constructFromPrePost(leftPre,leftPost);
        root->right = constructFromPrePost(rightPre,rightPost);
        return root;
    }
};