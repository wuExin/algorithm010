/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    int maxDepth(Node* root) {
        if(root == NULL) {
            return 0;
        }
        vector<int> depth;
        for(auto& sub : root->children) {
            depth.push_back(maxDepth(sub));
        }
        int maxDepthValue = 0;
        for(int i = 0;i<depth.size();i++) {
            maxDepthValue = max(maxDepthValue,depth[i]);
        }
        return maxDepthValue + 1;
    }
};