
#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    bool dfs(int node, const vector<vector<int>>& graph, vector<int>& state) {
        if (state[node] > 0) {
            return state[node] == 2;
        }
        state[node] = 1; 
        for (int neighbor : graph[node]) {
            if (!dfs(neighbor, graph, state)) {
                return false; 
            }
        }
        state[node] = 2; 
        return true;
    }

public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> state(n, 0);
        vector<int> safeNodes;
        
        for (int i = 0; i < n; i++) {
            if (dfs(i, graph, state)) {
                safeNodes.push_back(i);
            }
        }
        
        return safeNodes;
    }
};