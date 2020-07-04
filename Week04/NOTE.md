学习笔记
二分查找:
①单调性
②存在边界
③能够通过索引访问

使用二分查找，寻找一个半有序数组 [4, 5, 6, 7, 0, 1, 2] 中间无序的地方
①如果左半部有序，且target位于左半部，则左半部继续使用二分，否则继续在右半部搜索
②如果右半部有序，且target位于右半部，则右半部继续使用二分，否则继续在左半部搜索

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        int mid = 0 ;
        while (left <= right) {
            mid = left + (right - left)/2;
            if (nums[mid] == target) {
                return mid;
            }
            if (nums[left] <= nums[mid]) {
                if (nums[left] <= target && target < nums[mid]) {
                    right = mid - 1;
                }
                else {
                    left = mid + 1;
                }
            }
            else {
                if(nums[mid] < target && target <= nums[right]) {
                    left = mid + 1;
                }
                else {
                    right = mid - 1;
                }
            }
        }
        return -1;  
    }
}; 