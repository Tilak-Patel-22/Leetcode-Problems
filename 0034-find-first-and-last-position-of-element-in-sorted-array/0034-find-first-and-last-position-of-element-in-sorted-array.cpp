class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        if(n == 0)
        {
            return {-1, -1};
        }
        int fi = -1;
        int si = -1;
        int count = 0;
        for(int i=0; i<n; i++){
            if(nums[i] == target && count == 0){
                fi=i;
                count++;
            }
            else if(nums[i] == target){
                si = i;
            }
        }

        if(fi >= -1 && si == -1){
            si = fi;
        }
        return {fi, si};
    }
};