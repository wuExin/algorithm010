class Solution {
public:
    string addStrings(string num1, string num2) {
        int i = num1.length() - 1;
        int j = num2.length() - 1;
        int add = 0;
        string res;
        while (i >=0 || j >= 0 || add != 0) {
            int temp1 = i >= 0 ? num1[i] - '0' : 0;
            int temp2 = j >= 0 ? num2[j] - '0' : 0;
            int result = (temp1 + temp2 + add) % 10 ;
            add = (temp1 + temp2 + add)/10;
            res.push_back(result + '0');
            i--;
            j--;
        }
        reverse(res.begin(),res.end());
        return res;
    }
};