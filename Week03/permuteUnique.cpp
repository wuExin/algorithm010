class Solution {
public:
    vector<vector<int>> res;

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        if(nums.size() == 0) {
            return res;
        }
        sort(nums.begin(),nums.end());
        vector<bool> numsl(nums.size(),true);
        vector<int> num;
        dfs(nums,num,numsl);
        return res;
    }
    void dfs(const vector<int>& nums,vector<int>& num,vector<bool> numsl) {
        if (num.size() == nums.size()) {
            res.push_back(num);
            return;
        }
        for (int i =0;i<nums.size();i++) {
            if (numsl[i]) {
            if (i>0 && nums[i] == nums[i-1] && numsl[i-1]) {
                continue;
            }
            num.push_back(nums[i]);
            numsl[i] = false;
            dfs(nums,num,numsl);
            num.pop_back();
            numsl[i] = true;
        }
        }
    }
};