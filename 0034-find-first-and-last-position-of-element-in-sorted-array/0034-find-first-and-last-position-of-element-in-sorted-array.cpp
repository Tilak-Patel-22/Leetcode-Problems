class Solution {
public:
    int firstOcc(vector<int>& nums, int n, int target) {
        for (int i = 0; i < n; i++) {
            if (nums[i] == target)
                return i;
        }
        return -1;
    }

    int lastOcc(vector<int>& nums, int n, int target) {
        for (int i = n - 1; i >= 0; i--) {
            if (nums[i] == target)
                return i;
        }
        return -1;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();

        int first = firstOcc(nums, n, target);
        int last = lastOcc(nums, n, target);
        return {first, last};
    }
};
