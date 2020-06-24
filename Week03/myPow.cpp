class Solution {
public:
    double myPow(double x, int n) {
        long long N = n;
        if (n < 0) {
            N = -N;
            x = 1/x;
        }
        return fastPow(x,N);
    }

    double fastPow(double x,int n) {
        if (n == 0) {
            return 1;
        }
        double sub = fastPow(x,n/2);
        //merge
        if (n%2 == 0) {
            return sub*sub;
        }
        else {
            return sub*sub*x;
        }
    }
};