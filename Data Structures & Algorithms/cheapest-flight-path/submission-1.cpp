class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int, int>>> graph(n);
        for(int i = 0; i < flights.size(); i++) {
            graph[flights[i][0]].push_back({flights[i][1], flights[i][2]});
        }
        vector<int> dist(n, INT_MAX);
        dist[src] = 0;
        queue<pair<int, pair<int, int>>> q;
        q.push({0, {src, 0}});
        while (!q.empty()) {
            auto p = q.front(); q.pop();
            int distance = p.first; auto p1 = p.second;
            int node = p1.first, stops = p1.second;
            if (stops > k) continue;
            for(auto it : graph[node]) {
                int n1 = it.first, weight = it.second;
                if (distance + weight < dist[n1]) {
                    dist[n1] = distance + weight;
                    q.push({dist[n1], {n1, stops + 1}});
                }
            }
        }
        if (dist[dst] == INT_MAX) return -1;
        else return dist[dst];
    }
};
