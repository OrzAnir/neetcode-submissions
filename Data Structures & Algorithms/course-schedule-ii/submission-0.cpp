class Solution {
public:
    bool dfs(int node, vector<int>& visited, vector<int>& pathVis, vector<vector<int>>& graph, stack<int>& st) {
        visited[node] = 1;
        pathVis[node] = 1;
        for(auto it : graph[node]) {
            if (pathVis[it]) return true;
            if (!visited[it]) {
                if (dfs(it, visited, pathVis, graph, st)) return true;
            }
        }
        pathVis[node] = 0;
        st.push(node);
        return false;
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int n = numCourses;
        vector<vector<int>> graph(n);
        for(int i = 0; i < prerequisites.size(); i++) {
            graph[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }
        stack<int> st;
        vector<int> visited(n, 0);
        vector<int> pathVis(n, 0);
        for(int i = 0; i < n; i++) {
            if (!visited[i]) {
                if (dfs(i, visited, pathVis, graph, st)) return {};
            }
        }
        vector<int> ans;
        while(!st.empty()) {
            ans.push_back(st.top()); st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
