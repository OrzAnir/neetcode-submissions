class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        map<pair<int, int>, int> visited;
        priority_queue<pair<int, vector<int>>, vector<pair<int, vector<int>>>, greater<pair<int, vector<int>>>> pq;
        pq.push({0, points[0]});
        int sum = 0;
        while(!pq.empty()) {
            auto p = pq.top(); pq.pop();
            int weight = p.first; vector<int> coordinate = p.second;
            int x = coordinate[0], y = coordinate[1];
            if (visited[{x, y}]) continue;
            visited[{x, y}] = 1;
            sum += weight;
            for(int i = 0; i < points.size(); i++) {
                if (points[i] == coordinate) continue;
                if (!visited[{points[i][0], points[i][1]}]) {
                    int distance = abs(points[i][0] - x) + abs(points[i][1] - y);
                    pq.push({distance, points[i]});
                }
            } 
        }
        return sum;
    }
};
