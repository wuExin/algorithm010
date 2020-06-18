// //小根堆
    // vector<int> topKFrequent(vector<int>& nums, int k) {
    //     map<int,int> mp;
    //     vector<int> ret;
    //     for (auto& num : nums) {
    //         mp[num]++;
    //     }
    //     priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
    //     for (auto iter = mp.begin();iter !=mp.end();iter++) {
    //         if(q.size() == k) {
    //             if(iter->second  >= q.top().first) {
    //                 q.pop();
    //                 q.push(make_pair(iter->second,iter->first));
    //             }
    //         }
    //         else {
    //             q.push(make_pair(iter->second,iter->first));
    //         }
    //     }
    //     while (!q.empty()) {
    //         ret.push_back(q.top().second);
    //         q.pop();
    //     }
    //     reverse(ret.begin(),ret.end());
    //     return ret;
    // }

    //大根堆
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int,int> mp;
        vector<int> ret;
        for (auto& num : nums) {
            mp[num]++;
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,less<pair<int,int>>> q;
        for (auto iter = mp.begin();iter !=mp.end();iter++) {
            q.push(make_pair(iter->second,iter->first));
        }
        for(int i = 0 ;i<k; i++) {
            ret.push_back(q.top().second);
            q.pop();
        }
        return ret;
    }