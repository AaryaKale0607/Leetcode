#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> result;
    vector<int> path;

    void backtrack(int n, int k, int start) {
        if (path.size() == k) {
            result.push_back(path);
            return;
        }

        for (int i = start; i <= n - (k - path.size()) + 1; i++) {
            path.push_back(i);
            backtrack(n, k, i + 1);
            path.pop_back();
        }
    }

    vector<vector<int>> combine(int n, int k) {
        backtrack(n, k, 1);
        return result;
    }
};