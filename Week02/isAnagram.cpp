bool isAnagram(string s, string t) {
        if(s.length() != t.length()) {
            return false;
        }
        std::map<char,int> counts;
        for (int i = 0; i<s.length();i++) {
            counts[s[i]] ++;
            counts[t[i]] --;
        }
        for (auto count : counts) {
            if(count.second < 0) {
                return false;
            }
        }
        return true;    
}


