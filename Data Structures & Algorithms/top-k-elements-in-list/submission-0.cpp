class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int, int> mpp;
        int n = nums.size();
        for(int x : nums) mpp[x]++;
        priority_queue<pair<int, int>, 
        vector<pair<int, int>>, 
        greater<pair<int, int>>> pq;
        for (auto it : mpp) {
            if (pq.size() < k) pq.push({it.second, it.first});
            else {
                auto p = pq.top();
                int freq = p.first, num = p.second;
                if (it.second > freq) {
                    pq.pop();
                    pq.push({it.second, it.first});
                }
            }
        }
        vector<int> ans;
        while(!pq.empty()) {
            auto p = pq.top(); pq.pop();
            ans.push_back(p.second);
        }
        return ans;
    }
};
