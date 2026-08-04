#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    unordered_map<string, vector<string>> memo;

    vector<string> solve(string s, unordered_set<string>& dict) {
        // If already calculated
        if (memo.count(s)) {
            return memo[s];
        }

        vector<string> result;

        // Base case
        if (s.empty()) {
            result.push_back("");
            return result;
        }

        for (int i = 1; i <= s.length(); i++) {
            string word = s.substr(0, i);

            // Check if prefix exists in dictionary
            if (dict.count(word)) {
                string remaining = s.substr(i);

                vector<string> sentences = solve(remaining, dict);

                for (string sentence : sentences) {
                    if (sentence.empty()) {
                        result.push_back(word);
                    } else {
                        result.push_back(word + " " + sentence);
                    }
                }
            }
        }

        return memo[s] = result;
    }

    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict(wordDict.begin(), wordDict.end());

        return solve(s, dict);
    }
};