class Solution {
public:
    vector<int> smallestK(vector<int>& arr, int k) {
        priority_queue<int,vector<int>,greater<int>> pQueue;
        vector<int> ret;
        for (auto& sub : arr) {
            pQueue.push(sub);
        }
        for(int i =0; i<k;i++) {
            ret.push_back(pQueue.top());
            pQueue.pop();       
        }
        return ret;
    }
};