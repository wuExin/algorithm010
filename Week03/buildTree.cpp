class Solution {
    
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {  
        if(preorder.size() == 0 || inorder.size() == 0) {
            return NULL;
        }
        TreeNode* root = new TreeNode(preorder[0]);
        int rootData =preorder[0];
        for (int rootIndex = 0; rootIndex<inorder.size(); rootIndex++) {
            if (rootData == inorder[rootIndex]) {
                vector<int> preLeft;
                vector<int> preRight;
                vector<int> inLeft;
                vector<int> inRight;
                for (int i = 1; i < rootIndex + 1;i++) {
                    preLeft.push_back(preorder[i]);
                }
                for (int i = rootIndex+1;i<preorder.size();i++) {
                    preRight.push_back(preorder[i]);
                    inRight.push_back(inorder[i]);
                }
                for(int i = 0;i<rootIndex;i++) {
                     inLeft.push_back(inorder[i]);
                }
                root->left  = buildTree(preLeft,inLeft);
                root->right = buildTree(preRight,inRight);                 
                break;
            }
        }
        return root;

    }
};