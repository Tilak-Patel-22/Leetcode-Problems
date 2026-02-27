class Solution {
public:
    vector<vector<int>> ans;

    void solve(vector<int>& c, int target, int i, vector<int>& path) {
        if (target == 0) {
            ans.push_back(path);
            return;
        }
        if (i == c.size() || target < 0) return;

        path.push_back(c[i]);
        solve(c, target - c[i], i, path);
        path.pop_back();

        solve(c, target, i + 1, path);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> path;
        solve(candidates, target, 0, path);
        return ans;
    }
};