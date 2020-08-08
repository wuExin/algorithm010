class Solution {
public:
    int numJewelsInStones(string J, string S) {
        int res = 0;
        unordered_map<char,int> map;
        for (auto& j : J) map[j]++;
        for (auto& s : S) if(map[s] != 0) res++;
        return res;
    }
};