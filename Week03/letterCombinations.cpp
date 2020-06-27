class Solution {
public:
    vector<string> res;
    map<char,string> mp;

    vector<string> letterCombinations(string digits) {
        if (digits.length() == 0) {
            return res;
        }       
        mp['2'] = "abc";
        mp['3'] = "def";
        mp['4'] = "ghi";
        mp['5'] = "jkl";
        mp['6'] = "mno";
        mp['7'] = "pqrs";
        mp['8'] = "tuv";
        mp['9'] = "wxyz";
        string  str = "";
        dfs(digits,str,0);
        return res;
        
    }
    void dfs(string digits,string str,int level) {
        if (digits.length() == level) {
            res.push_back(str);
            return;
        }
        for (int i = 0;i<mp[digits[level]].length();i++) {
            str.push_back(mp[digits[level]][i]);
            dfs(digits,str,level+1);
            str.pop_back();
        }
    }
};