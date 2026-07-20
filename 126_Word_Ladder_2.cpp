#include<vector>
#include<unordered_map>
#include<unordered_set>
#include<string>
#include<queue>
#include<functional>

using namespace std;

class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
           unordered_set<string> dict(wordList.begin(), wordList.end());
        vector<vector<string>> ans;

        if (!dict.count(endWord)) return ans;

        unordered_map<string, vector<string>> parents;
        unordered_map<string, int> level;

        queue<string> q;
        q.push(beginWord);
        level[beginWord] = 0;

        int wordLen = beginWord.size();

        while (!q.empty()) {
            string word = q.front();
            q.pop();
            int currLevel = level[word];

            string temp = word;
            for (int i = 0; i < wordLen; i++) {
                char original = temp[i];

                for (char c = 'a'; c <= 'z'; c++) {
                    temp[i] = c;
                    if (!dict.count(temp)) continue;

                    if (!level.count(temp)) {
                        level[temp] = currLevel + 1;
                        q.push(temp);
                        parents[temp].push_back(word);
                    } else if (level[temp] == currLevel + 1) {
                        parents[temp].push_back(word);
                    }
                }

                temp[i] = original;
            }
        }

        if (!level.count(endWord)) return ans;

        vector<string> path;

        function<void(string)> dfs = [&](string word) {
            path.push_back(word);

            if (word == beginWord) {
                vector<string> curr(path.rbegin(), path.rend());
                ans.push_back(curr);
            } else {
                for (string &p : parents[word]) {
                    dfs(p);
                }
            }

            path.pop_back();
        };

        dfs(endWord);

        return ans;
    }
};