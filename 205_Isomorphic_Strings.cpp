#include <vector>
#include <string>
using namespace std ;
class Solution {
public:
    bool isIsomorphic(string s, string t) {
         if (s.length() != t.length())
            return false;

        vector<int> sToT(256, -1);
        vector<int> tToS(256, -1);

        for (int i = 0; i < s.length(); i++) {
            int a = s[i];
            int b = t[i];

            // Check existing mappings
            if (sToT[a] != -1 && sToT[a] != b)
                return false;

            if (tToS[b] != -1 && tToS[b] != a)
                return false;

            // Create mapping
            sToT[a] = b;
            tToS[b] = a;
        }

        return true;
    }
};