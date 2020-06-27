class Solution {
public:
    vector<vector<int>> result;

    vector<vector<int>> permute(vector<int>& nums) {
        if (nums.size() == 0) {
            return result;
        }
        vector<int> res;
        dfs(nums,res);
        return result;
    }
    void dfs(const vector<int>& nums,vector<int>& res) {
        if (nums.size() == res.size()) {
            result.push_back(res);
            return;
        }
        for (int i=0;i<nums.size();i++) {
            int flag = true;
            for (int sub:res) {
                if(sub == nums[i]) {
                    flag = false;
                    break;
                }
            }
            if (flag) {      
                res.push_back(nums[i]);
                dfs(nums,res);
                res.pop_back();
            }
        }
    }
};