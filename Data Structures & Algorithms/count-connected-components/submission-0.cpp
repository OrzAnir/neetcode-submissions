class DisjointSet {
public:
    vector<int> parent, rank;
    DisjointSet(int n) {
        parent.resize(n + 1, 0);
        rank.resize(n + 1, 0);
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
            rank[x]++;
        }
        else if (rank[x] > rank[y]) parent[y] = x;
        else parent[x] = y;
    }
};

class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        DisjointSet ds(n);
        for(int i = 0; i < edges.size(); i++) {
            if (ds.findParent(edges[i][0]) != ds.findParent(edges[i][1])) {
                ds.unionRank(edges[i][0], edges[i][1]);
            }
        }
        int components = 0;
        for(int i = 0; i < n; i++) {
            if (ds.parent[i] == i) components += 1; 
        }
        return components;
    }
};
