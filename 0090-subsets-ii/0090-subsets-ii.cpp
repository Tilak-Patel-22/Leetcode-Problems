class Solution {
public:
    void helper(int idx, vector<int>& nums, vector<int>& cur, vector<vector<int>>& ans) {
        if (idx <= nums.size()) {
            ans.push_back(cur);
        }
        for (int i = idx; i < nums.size(); i++) {
            if (i > idx && nums[i] == nums[i - 1]) continue;
            cur.push_back(nums[i]);
            helper(i + 1, nums, cur, ans);
            cur.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        vector<int> cur;
        helper(0, nums, cur, ans);
        return ans;
    }
};
