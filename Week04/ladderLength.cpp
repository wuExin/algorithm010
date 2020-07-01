class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> wordSet;
        for (auto &word : wordList) {
            wordSet.insert(word);
        }
        queue<pair<string,int>> wordQueue;
        wordQueue.push(pair<string,int>(beginWord,1));

        while (!wordQueue.empty()) {
            if (wordQueue.front().first == endWord) {
                return wordQueue.front().second;
            }
            string temp = wordQueue.front().first;
            int step = wordQueue.front().second;
            wordQueue.pop();
            char ch;
            for (int i = 0;i < temp.length();i++) {
                ch = temp[i];
                for (char c = 'a';c <='z';c++) {
                    if (c == temp[i]) {
                        continue;
                    }
                    temp[i] = c;
                    if (wordSet.find(temp) != wordSet.end()) {
                        wordQueue.push(pair<string,int>(temp,step+1));
                        wordSet.erase(temp);
                    }
                    temp[i] = ch;
                }
            }
        }
 
        return 0;
    }
};