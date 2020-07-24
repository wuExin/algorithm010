class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
        set<string> bankSet(bank.begin(),bank.end());
        queue<pair<string,int>> strQueue;
        strQueue.push(pair<string,int>(start,0));

        while (!strQueue.empty()) {
            if (strQueue.front().first == end) {
                return strQueue.front().second;
            }
            string gene = strQueue.front().first;
            int step = strQueue.front().second;
            strQueue.pop();
            for (int i = 0;i < gene.length();i++) {
                char temp = gene[i];
                for (auto base : "ACGT") {
                    if (base == gene[i]) {
                        continue;
                    }
                    gene[i] = base;
                    if (bankSet.find(gene) != bankSet.end()) {
                        strQueue.push(pair<string,int>(gene,step + 1));
                        bankSet.erase(gene);
                    }
                    gene[i] = temp;
                }
            }
        }
        return -1;
    }
};