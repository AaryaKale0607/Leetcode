#include <vector>
using namespace std ;
class Solution {
private:
    vector<vector<int>> result;
    vector<int> current;

    void backtrack(int start, int k, int n) {
        if (current.size() == k) {
            if (n == 0) {
                result.push_back(current);
            }
            return;
        }

        for (int i = start; i <= 9; i++) {
            if (i > n) {
                break;
            }

            current.push_back(i);

            backtrack(i + 1, k, n - i);

            current.pop_back();
        }
    }

public:
    vector<vector<int>> combinationSum3(int k, int n) {
        backtrack(1, k, n);
        return result;
    }
};
