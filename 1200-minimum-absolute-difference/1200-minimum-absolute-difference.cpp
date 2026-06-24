class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int t = INT_MAX;
        for(int i = 1; i<arr.size(); i++){
            t = min(t, arr[i] - arr[i-1]);
        }
        vector<vector<int>> ans;
        for(int i=1; i<arr.size(); i++){
            if(arr[i] - arr[i-1] == t){
                ans.push_back({arr[i-1],arr[i]});
            }
        }
        return ans;
    }
};