class Solution {
public:
    int orangesRotting(vector<vector<int>>& g) {
        int m = g.size(), n = g[0].size(), time = 0;

        while (true) {
            bool changed = false;
            vector<vector<int>> t = g;

            for (int i = 0; i < m; i++) {
                for (int j = 0; j < n; j++) {
                    if (g[i][j] == 2) {
                        if (i > 0 && g[i-1][j] == 1) t[i-1][j] = 2, changed = true;
                        if (i < m-1 && g[i+1][j] == 1) t[i+1][j] = 2, changed = true;
                        if (j > 0 && g[i][j-1] == 1) t[i][j-1] = 2, changed = true;
                        if (j < n-1 && g[i][j+1] == 1) t[i][j+1] = 2, changed = true;
                    }
                }
            }

            if (!changed) break;
            g = t;
            time++;
        }

        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (g[i][j] == 1) return -1;

        return time;
    }
};