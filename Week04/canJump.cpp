class Solution {
public:
    bool canJump(vector<int>& nums) {
        if (nums.size() == 0){
            return false;
        }
        int end = nums.size() - 1;

        for (int i = nums.size() - 2; i>=0; i--) {
            if (nums[i] + i >= end) {
                end = i;
            }
        }
        return end == 0;
    }
};