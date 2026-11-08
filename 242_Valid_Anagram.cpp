#include<string>
#include<vector>
using namespace std ;
class Solution {
public:
    bool isAnagram(string s, string t) {
         // Different lengths cannot be anagrams
        if (s.length() != t.length()) {
            return false;
        }

        vector<int> freq(26, 0);

        // Count characters in s
        for (char c : s) {
            freq[c - 'a']++;
        }

        // Decrease counts using characters in t
        for (char c : t) {
            freq[c - 'a']--;

            if (freq[c - 'a'] < 0) {
                return false;
            }
        }

        return true;
    }
};