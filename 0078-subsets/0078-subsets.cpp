class Solution {
public:
    vector<vector<int>> ans;
    void backtrack(int start, vector<int>& nums, vector<int>& temp) {
        ans.push_back(temp);
        for(int i=start; i<nums.size(); i++) {
            temp.push_back(nums[i]);
            backtrack(i+1, nums, temp);
            temp.pop_back();
        }
    }
        vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> temp;
        backtrack(0, nums, temp);
        return ans;
    }
};
