class Solution{
public:
    int min = INT_MAX;
    int findMin (vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;
        binarySearch(nums,left,right);
        return min;
    }

    void binarySearch (vector<int>& nums,int left,int right) {
        if (right - left <= 1) {
		if (nums[left] < nums[right]) {
			min = min > nums[left] ? nums[left] : min;
		}
		else {
			min = min > nums[right] ? nums[right] : min;
		}
		return;
	    }
        int mid = left + (right - left) / 2;
        if (nums[left] < nums[mid]) {
            min = min > nums[left] ? nums[left] : min;
            binarySearch(nums,mid + 1,right);
        }
        else {
           min = min > nums[mid] ? nums[mid] : min;
           binarySearch(nums,left,mid - 1); 
        }
    }
};