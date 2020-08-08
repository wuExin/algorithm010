class Solution {
public:
    int lengthOfLastWord(string s) {
        int res = 0;
        bool isNull = false;
        for (int i = 0; i < s.length();i++) {
            if (s[i] != ' ') {
                if (isNull) res = 1;
                else res++;
                isNull = false;
            }
            else isNull = true;
        }
        return res;       
    }
};