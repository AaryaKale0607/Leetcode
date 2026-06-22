#include <vector>
#include <string>
#include <functional>

using namespace std;

class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> result;
        string current;

        function<void(int, int)> backtrack = [&](int index, int parts) {
            if (parts == 4 && index == s.size()) {
                result.push_back(current.substr(0, current.size() - 1));
                return;
            }

            if (parts == 4 || index == s.size()) return;

            for (int len = 1; len <= 3 && index + len <= s.size(); len++) {
                string segment = s.substr(index, len);

                if (segment.size() > 1 && segment[0] == '0') break;

                int value = stoi(segment);
                if (value > 255) break;

                int oldSize = current.size();
                current += segment + '.';

                backtrack(index + len, parts + 1);

                current.resize(oldSize);
            }
        };

        backtrack(0, 0);
        return result;
    }
};