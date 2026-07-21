class Solution {
public:
    bool dfs(int node, int parent, vector<int>& visited, vector<vector<int>>& graph) {
        visited[node] = 1;
        for(auto it : graph[node]) {
            if (visited[it] && it != parent) return true;
            else if (!visited[it]) {
                if (dfs(it, node, visited, graph)) return true;
            }
        }
        return false;
    }
    bool validTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>> graph(n);
        for(int i = 0; i < edges.size(); i++) {
            graph[edges[i][0]].push_back(edges[i][1]);
            graph[edges[i][1]].push_back(edges[i][0]);
        }
        vector<int> visited(n);
        int components = 0;
        for(int i = 0; i < n; i++) {
            if (!visited[i]) {
                components += 1;
                if (components > 1) return false;
                if (dfs(i, -1, visited, graph)) return false;
            }
        }
        return true;
    }
};
