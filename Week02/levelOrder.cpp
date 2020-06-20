class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> res;
        if (root == NULL) {
            return res;
        }
        queue<Node*> q;
        q.push(root);
        while (!q.empty()) {
            int size = q.size();
            vector<int> curLevel;
            for (int i = 0; i<size; i++) {
                Node* front = q.front();
                q.pop();
                curLevel.push_back(front->val);
                for (auto children : front->children) {
                    q.push(children);
                }
            }
            res.push_back(curLevel);
        }
        return res;
    }
};