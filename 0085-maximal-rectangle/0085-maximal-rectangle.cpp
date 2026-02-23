class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        heights.push_back(0);
        int n = heights.size(), ans = 0;
        for(int i = 0; i < n; i++) {
            while(!st.empty() && heights[st.top()] > heights[i]) {
                int h = heights[st.top()];
                st.pop();
                int w = st.empty() ? i : i - st.top() - 1;
                ans = max(ans, h * w);
            }
            st.push(i);
        }
        return ans;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        if(matrix.empty()) return 0;
        int n = matrix[0].size(), ans = 0;
        vector<int> heights(n, 0);

        for(auto& row : matrix) {
            for(int i = 0; i < n; i++)
                heights[i] = (row[i] == '1') ? heights[i] + 1 : 0;
            ans = max(ans, largestRectangleArea(heights));
        }
        return ans;
    }
};