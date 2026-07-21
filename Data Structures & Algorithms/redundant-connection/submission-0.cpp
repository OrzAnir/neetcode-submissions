class DisjointSet {
public:
    vector<int> rank, parent;
    DisjointSet(int n) {
        rank.resize(n + 1, 0);
        parent.resize(n + 1, 0);
        for(int i = 0; i < n; i++) parent[i] = i;
    }
    int findParent(int node) {
        if (parent[node] == node) return node;
        return parent[node] = findParent(parent[node]);
    }
    void unionRank(int u, int v) {
        int x = findParent(u);
        int y = findParent(v);
        if (rank[x] == rank[y]) {
            parent[y] = x;
            rank[x] += 1;
        }
        else if (rank[x] > rank[y]) parent[y] = x;
        else parent[x] = y;
    }
};
class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        vector<int> ans;
        int n = edges.size();
        DisjointSet ds(n);
        for(int i = 0; i < n; i++) {
            if (ds.findParent(edges[i][0]) == ds.findParent(edges[i][1])) {
                ans = edges[i];
            }
            else ds.unionRank(edges[i][0], edges[i][1]);
        }
        return ans;
    }
};
