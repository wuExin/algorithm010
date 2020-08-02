class Solution {
public:
    int reversePairs(vector<int>& nums) {
        vector<int> tmp(nums.size(),0);
        return mergeSort(nums,tmp,0,nums.size()-1);
    }
    int mergeSort(vector<int>& nums, vector<int>& tmp, int l, int r){
        if(l >= r) {
            return 0;
        }
        int mid = l + ((r - l) >> 1);
        int count = mergeSort(nums,tmp,l,mid) + mergeSort(nums,tmp,mid+1,r);
        int i = l;
        int j = mid + 1;
        int pos = l;
        
        while(i <= mid && j <= r) {
            if(nums[i] <= nums[j]) {
                tmp[pos++] = nums[i++];
                count += (j - (mid + 1));
            }
            else tmp[pos++] = nums[j++];      
        }
        while(i <= mid) {
          tmp[pos++] = nums[i++];
          count += (j - (mid + 1));
        }
        while(j <= r) tmp[pos++] = nums[j++];
        // for(int i = 0; i < temp.size();i++) {
        //     nums[left + i] = temp[i];
        // }
        copy(tmp.begin() + l, tmp.begin() + r + 1, nums.begin() + l);
        return count;
    }
};