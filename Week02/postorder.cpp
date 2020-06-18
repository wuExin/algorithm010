class Solution {
public:
    // vector<int> res;
    // vector<int> postorder(Node* root) {
    //     if(!root)   return res;
    //     for(auto i : root -> children){
    //         postorder(i);
    //     }
    //     res.push_back(root -> val);
    //     return res;
    // }

    vector<int> postorder(Node* root) {
    if(root==NULL) return {};
    vector<int> res;
    stack<Node*> stk;
    stk.push(root);
    while(!stk.empty())
    {
        Node* temp=stk.top();
        stk.pop();
        for(int i=0;i<temp->children.size();i++) stk.push(temp->children[i]);
        res.push_back(temp->val);
    }
    reverse(res.begin(), res.end());
    return res;
}
};