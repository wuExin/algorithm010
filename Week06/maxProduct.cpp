class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = 0;
        int res = 0;
        for(auto& num : nums) {
            if(sum > 0) {
                sum += num;
            }
            else {
                sum = num;
            }
            res = max(res,sum);
        }
        return res;       
    }
};