#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
   unordered_map<string, bool> memo;

    bool solve(const string& s1, const string& s2) {
        if (s1 == s2) return true;

        string key = s1 + "#" + s2;
        if (memo.count(key)) return memo[key];

        int n = s1.size();

        // Prune: character frequencies must match
        vector<int> freq(26, 0);
        for (int i = 0; i < n; i++) {
            freq[s1[i] - 'a']++;
            freq[s2[i] - 'a']--;
        }

        for (int x : freq) {
            if (x != 0)
                return memo[key] = false;
        }

        for (int i = 1; i < n; i++) {
            // No swap case
            if (solve(s1.substr(0, i), s2.substr(0, i)) &&
                solve(s1.substr(i), s2.substr(i))) {
                return memo[key] = true;
            }

            // Swap case
            if (solve(s1.substr(0, i), s2.substr(n - i)) &&
                solve(s1.substr(i), s2.substr(0, n - i))) {
                return memo[key] = true;
            }
        }

        return memo[key] = false;
    }

    bool isScramble(string s1, string s2) {
        if (s1.size() != s2.size()) return false;
        return solve(s1, s2);
    }
};