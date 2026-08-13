#include <string>

using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        string ans;
        int i = s.length() - 1;

        while (i >= 0) {
            // Skip spaces
            while (i >= 0 && s[i] == ' ')
                i--;

            if (i < 0)
                break;

            // Find the beginning of the word
            int j = i;
            while (j >= 0 && s[j] != ' ')
                j--;

            // Add word
            if (!ans.empty())
                ans += ' ';

            ans += s.substr(j + 1, i - j);

            i = j - 1;
        }

        return ans;
    }
};