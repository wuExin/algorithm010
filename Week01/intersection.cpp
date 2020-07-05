class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        set<int> set1;
        set<int> set2(nums2.begin(),nums2.end());
        for (auto& i : nums1) {
            if (set2.count(i) == 1) {
                set1.insert(i);
            }
        }
        return vector<int>(set1.begin(),set1.end());
    }
};