class Solution {
public:
    int noOfDays(vector<int>& weight, int capacity) {
        int days = 1;
        int load = 0;

        for (int i = 0; i < weight.size(); i++) {
            if (load + weight[i] > capacity) {
                days++;
                load = 0;
            }
            load += weight[i];
        }
        return days;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int low = 0, high = 0;

        for (int i = 0; i < weights.size(); i++) {
            low = max(low, weights[i]);
            high += weights[i];
        }

        while (low < high) {
            int mid = (low + high) / 2;

            if (noOfDays(weights, mid) <= days)
                high = mid;
            else
                low = mid + 1;
        }
        return low;
    }
};
