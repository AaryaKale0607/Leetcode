#include<iostream>
#include<string>
#include<stack>
#include <algorithm>
using namespace std;
class Solution {    
public:
    string removeStars(string s) {
          stack<char> stk;

        for (auto ch : s) {
            if (ch != '*') {
                stk.push(ch);   // push normal characters
            } 
            else {
                if (!stk.empty()) {
                    stk.pop();  // remove previous character
                }
            }
        }

        string ans = "";

        // Build result from stack (reverse order)
        while (!stk.empty()) {
            ans += stk.top();
            stk.pop();
        }

        // Reverse because stack gives reversed order
        reverse(ans.begin(), ans.end());

        return ans;
    }
};
