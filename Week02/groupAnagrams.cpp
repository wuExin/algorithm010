vector<vector<string>> groupAnagrams(vector<string>& strs) {
            map<string,vector<string>> mp;
            for (auto& str: strs) {
                string temp = str;
                sort(temp.begin(),temp.end());
                mp[temp].push_back(str);
            }
            vector<vector<string>> result;
            for (auto& m : mp) {
                result.push_back(m.second);
            }
            return result;
}


