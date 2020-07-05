class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
        int min = 1e7;
        sort(nums.begin(),nums.end());
        for (int i = 0;i<nums.size() - 2;i++) {
            if(i > 0 && nums[i] == nums[i-1]) continue;
            int j = i + 1;
            int k = nums.size() - 1;
            while (j < k) {
                int sum = nums[i] + nums[j] + nums[k];
                min = abs(min - target) > abs(sum - target) ? sum : min;
                if(sum < target) {
                    j++;
                }
                else if (sum > target) {
                    k--;
                }
                else
                {
                    return target;
                }
            }
        }
        return min;        
    }
};