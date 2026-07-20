class Solution {
public: 
    bool dfs(int node, vector<int>& visited, vector<int>& pathVis, vector<vector<int>>& graph) {
        visited[node] = 1;
        pathVis[node] = 1;
        for(auto it : graph[node]) {
            if (pathVis[it]) return true;
            if (!visited[it]) {
                if (dfs(it, visited, pathVis, graph)) return true;
            }
        }
        pathVis[node] = 0;
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int n = numCourses;
        vector<vector<int>> graph(n);
        for(int i = 0; i < prerequisites.size(); i++) {
            graph[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }
        vector<int> visited(n);
        vector<int> pathVis(n);
        for(int i = 0; i < n; i++) {
            if (!visited[i]) {
                if (dfs(i, visited, pathVis, graph)) return false;
            }
        }
        return true;
    }
};
