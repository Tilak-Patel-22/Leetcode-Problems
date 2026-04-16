class Solution {
public:
    vector<int> parent;

    int find(int x) {
        if (parent[x] != x) parent[x] = find(parent[x]);
        return parent[x];
    }

    void unite(int x, int y) {
        parent[find(x)] = find(y);
    }

    int makeConnected(int n, vector<vector<int>>& connections) {
        if (connections.size() < n - 1) return -1;
        parent.resize(n);
        for (int i = 0; i < n; i++) parent[i] = i;
        for (auto &c : connections) unite(c[0], c[1]);
        unordered_set<int> st;
        for (int i = 0; i < n; i++) st.insert(find(i));
        return st.size() - 1;
    }
};