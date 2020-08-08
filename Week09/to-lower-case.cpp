class Solution {
public:
    string toLowerCase(string str) {
        for (auto& sub : str) {
            if (65<= sub && sub <= 90) {
                sub += 32;
            }
        }
        return str;
    }
};