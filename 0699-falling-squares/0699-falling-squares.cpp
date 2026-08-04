class Solution {
public:
    vector<int> fallingSquares(vector<vector<int>>& positions) {
        vector<pair<pair<int,int>, int>> intervals;
        vector<int> ans;
        int maxHeight = 0;

        for (auto &p : positions) {
            int left = p[0];
            int right = left + p[1];
            int height = p[1];

            int base = 0;

            for (auto &in : intervals) {
                int l = in.first.first;
                int r = in.first.second;

                if (max(left, l) < min(right, r))
                    base = max(base, in.second);
            }

            int curr = base + height;
            intervals.push_back({{left, right}, curr});

            maxHeight = max(maxHeight, curr);
            ans.push_back(maxHeight);
        }

        return ans;
    }
};