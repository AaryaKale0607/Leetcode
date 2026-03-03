#include<iostream>
#include<string>
#include<stack>
using namespace std;
class Solution {
public:
    string reversePrefix(string word, char ch) {
          stack<char> stk;
        string ans = "";
        int n = word.size();
        int index = -1;

        // Find first occurrence of ch
        for (int i = 0; i < n; i++) {
            if (word[i] == ch) {
                index = i;
                break;
            }
        }

        // If character not found, return original word
        if (index == -1) return word;

        // Push characters into stack till index
        for (int i = 0; i <= index; i++) {
            stk.push(word[i]);
        }

        // Pop from stack to reverse prefix
        while (!stk.empty()) {
            ans += stk.top();
            stk.pop();
        }

        // Append remaining characters
        for (int i = index + 1; i < n; i++) {
            ans += word[i];
        }

        return ans;
    }
};

