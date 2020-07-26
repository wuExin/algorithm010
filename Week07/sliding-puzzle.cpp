class Solution {
public:
    int slidingPuzzle(vector<vector<int>>& board) {
        int m = board.size();
        int n = board[0].size();
        string start;
        string end = "123450";
        for (int i = 0; i < m; i++) for (int j = 0; j < n; j++) start.push_back(board[i][j] + '0');
        vector<vector<int>> neighbor = {
            { 1, 3 },
            { 0, 4, 2 },
            { 1, 5 },
            { 0, 4 },
            { 3, 1, 5 },
            { 4, 2 }
        };
        unordered_set<string> boardSet;
        queue<string> boardQueue;
        boardQueue.push(start);
        int distance = 0;
        while(!boardQueue.empty()) {
            int size = boardQueue.size();
            for(int i = 0; i < size;i++) {
                string front = boardQueue.front();
                boardQueue.pop();
                if(front == end) return distance;
                int index = 0;
                for (;front[index] != '0'; index++);
                for(auto j : neighbor[index]) {
                    string temp = front;
                    swap(temp[index],temp[j]);
                    if(boardSet.count(temp) == 0) {
                        boardQueue.push(temp);
                        boardSet.insert(temp);
                    }
                }
            }
            distance++;
        }   
        return -1;

    }
};