class Solution {
public:
    int mySqrt (int x) {
        if  (x == 0) {
            return 0;
        }
        if (x == 1) {
            return 1;
        }
        long left  = 1;
        long right =  x;
        long mid = 1;
        while (left <= right) {
            mid = left + (right - left)/2;
            if (mid * mid == x) {
                return mid;
            }
            else if (mid*mid < x) {
                left = mid + 1;
            }
            else if (mid*mid > x) {
                right = mid -1;
            }
        }
        return right;
    }
}; 