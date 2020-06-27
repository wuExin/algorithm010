class Solution {
    std::vector<vector<int>> res;
public:
    vector<vector<int>> subsets(vector<int>& nums) {
         
         if (nums.size() == 0 ){
             return {{}};
         }
         int n = nums.back();
         nums.pop_back();
         res = subsets(nums);
         int size = res.size();

         for (int i=0; i< size; i++) {
             res.push_back(res[i]);
             res.back().push_back(n);
         }
         return res;
    }
};