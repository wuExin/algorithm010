class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
       vector<int> ret;
       map<int,int> mp;
       int i = 0;
       for (auto& num : nums) {
           int sum = target - num;
           if (mp.find(sum) != mp.end()) {
               ret.push_back(mp[sum]);
               ret.push_back(i);
               return ret;
           }
           mp[num] = i;
           i++;
       }
       return ret;
    }
};