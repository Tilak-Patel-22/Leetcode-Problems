class Solution {
public:
    int minSwap(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();

        int keep = 0;
        int swp = 1;

        for (int i = 1; i < n; i++) {
            int newKeep = INT_MAX;
            int newSwap = INT_MAX;

            if (nums1[i] > nums1[i - 1] && nums2[i] > nums2[i - 1]) {
                newKeep = min(newKeep, keep);
                newSwap = min(newSwap, swp + 1);
            }

            if (nums1[i] > nums2[i - 1] && nums2[i] > nums1[i - 1]) {
                newKeep = min(newKeep, swp);
                newSwap = min(newSwap, keep + 1);
            }

            keep = newKeep;
            swp = newSwap;
        }

        return min(keep, swp);
    }
};