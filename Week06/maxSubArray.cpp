class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxValue = INT_MIN,imax = 1,imin = 1;
        for(auto& num:nums) {
            if(num < 0) {
                imax^=imin;
                imin^=imax;
                imax^=imin;   
            }
            imax = max(imax*num, num);
            imin = min(imin*num, num);
            maxValue  = max(imax,maxValue);
        }
        return maxValue;
    }
};