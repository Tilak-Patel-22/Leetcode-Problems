class Solution {
public:
    unordered_map<int, int> parent;

    int find(int x) {
        if (!parent.count(x)) parent[x] = x;
        if (parent[x] != x) parent[x] = find(parent[x]);
        return parent[x];
    }

    void unite(int x, int y) {
        parent[find(x)] = find(y);
    }

    int removeStones(vector<vector<int>>& stones) {
        for (auto &s : stones) unite(s[0], ~s[1]);
        unordered_set<int> st;
        for (auto &p : parent) st.insert(find(p.first));
        return stones.size() - st.size();
    }
};