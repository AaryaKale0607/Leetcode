#include <vector>
#include <unordered_map>
#include <queue>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
         vector<pair<int, int>> events;

        for (auto& b : buildings) {
            events.push_back({b[0], -b[2]}); // Building starts
            events.push_back({b[1], b[2]});  // Building ends
        }

        sort(events.begin(), events.end());

        priority_queue<int> maxHeap;
        maxHeap.push(0);

        unordered_map<int, int> count;
        count[0] = 1;

        vector<vector<int>> result;
        int prevHeight = 0;

        for (int i = 0; i < events.size(); ) {
            int x = events[i].first;

            while (i < events.size() && events[i].first == x) {
                int h = events[i].second;

                if (h < 0) {
                    maxHeap.push(-h);
                    count[-h]++;
                } else {
                    count[h]--;
                }

                i++;
            }

            while (!maxHeap.empty() && count[maxHeap.top()] == 0) {
                maxHeap.pop();
            }

            int currHeight = maxHeap.top();

            if (currHeight != prevHeight) {
                result.push_back({x, currHeight});
                prevHeight = currHeight;
            }
        }

        return result;
    }
};