#include <string>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
         int n = s.length();
        if (n == 0) return "";

        int start = 0, maxLen = 1;

        // Helper function to expand around center
        auto expand = [&](int left, int right) {
            while (left >= 0 && right < n && s[left] == s[right]) {
                left--;
                right++;
            }
            // length of palindrome
            int len = right - left - 1;
            if (len > maxLen) {
                maxLen = len;
                start = left + 1;
            }
        };

        for (int i = 0; i < n; i++) {
            // Odd length palindrome
            expand(i, i);
            // Even length palindrome
            expand(i, i + 1);
        }

        return s.substr(start, maxLen);
    }
};