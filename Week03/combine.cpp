class Solution {
public:
    vector<vector<int>> result;

    vector<vector<int>> combine(int n, int k) {
        if (n<=0 || k<=0) {
            return result;
        }
        vector<int> res;
        dfs(n,k,1,res);
        return result;
    }
    void dfs (int n,int k,int start,vector<int>& res) {
        if (res.size() == k) {
            result.push_back(res);
            return;
        }
        for (int i = start ;i<=n; i++) {
            res.push_back(i);
            dfs(n,k,i+1,res);
            res.pop_back();
        }
    }
    
};