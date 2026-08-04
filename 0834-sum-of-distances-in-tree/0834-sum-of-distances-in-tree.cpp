class Solution {
public:
    vector<vector<int>> graph;
    vector<int> count, ans;

    void dfs1(int node, int parent) {
        count[node] = 1;

        for (int child : graph[node]) {
            if (child == parent) continue;

            dfs1(child, node);
            count[node] += count[child];
            ans[node] += ans[child] + count[child];
        }
    }

    void dfs2(int node, int parent, int n) {
        for (int child : graph[node]) {
            if (child == parent) continue;

            ans[child] = ans[node] - count[child] + (n - count[child]);
            dfs2(child, node, n);
        }
    }

    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        graph.resize(n);
        count.resize(n);
        ans.resize(n);

        for (auto &e : edges) {
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
        }

        dfs1(0, -1);
        dfs2(0, -1, n);

        return ans;
    }
};