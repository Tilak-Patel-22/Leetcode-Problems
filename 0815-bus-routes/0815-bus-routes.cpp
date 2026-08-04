class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        if (source == target) return 0;

        unordered_map<int, vector<int>> stopToBus;

        for (int i = 0; i < routes.size(); i++) {
            for (int stop : routes[i])
                stopToBus[stop].push_back(i);
        }

        queue<int> q;
        unordered_set<int> visitedStops;
        unordered_set<int> visitedBus;

        q.push(source);
        visitedStops.insert(source);

        int buses = 0;

        while (!q.empty()) {
            int sz = q.size();
            buses++;

            while (sz--) {
                int stop = q.front();
                q.pop();

                for (int bus : stopToBus[stop]) {
                    if (visitedBus.count(bus))
                        continue;

                    visitedBus.insert(bus);

                    for (int nextStop : routes[bus]) {
                        if (nextStop == target)
                            return buses;

                        if (!visitedStops.count(nextStop)) {
                            visitedStops.insert(nextStop);
                            q.push(nextStop);
                        }
                    }
                }
            }
        }

        return -1;
    }
};