class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> graph(n + 1);
        for(int i = 0; i < times.size(); i++) {
            graph[times[i][0]].push_back({times[i][1], times[i][2]});
        }
        vector<int> dist(n + 1, INT_MAX);
        dist[k] = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, k});
        while(!pq.empty()) {
            auto p = pq.top(); pq.pop();
            int distance = p.first, node = p.second;
            for(auto it : graph[node]) {
                int n1 = it.first, weight = it.second;
                if (distance + weight < dist[n1]) {
                    dist[n1] = distance + weight;
                    pq.push({dist[n1], n1});
                }
            }
        }
        int maxi = -1;
        for(int i = 1; i < n + 1; i++) {
            if (dist[i] == INT_MAX) return -1;
            maxi = max(maxi, dist[i]);
        }
        return maxi;
    }
};
