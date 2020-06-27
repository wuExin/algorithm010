class Solution {
public:
    int majorityElement(vector<int>& nums) {
        map<int,int> mp;
        for (auto num:nums) {
            if (++mp[num] > nums.size()/2) {
                return num;
            }
        }
        // for (auto ite = mp.begin();ite != mp.end();ite++) {
        //     if(ite->second > nums.size()/2) {
        //         return ite->first;
        //     }
        // }
        return 0;    
    }
};