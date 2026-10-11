#include<vector>
#include<string>
using namespace std ;
class Solution {
private:
    struct TrieNode {
        TrieNode* children[26];
        string word;

        TrieNode() {
            for (int i = 0; i < 26; i++) {
                children[i] = nullptr;
            }
            word = "";
        }
    };

    TrieNode* root = new TrieNode();

    void insert(string& word) {
        TrieNode* curr = root;

        for (char ch : word) {
            int idx = ch - 'a';

            if (curr->children[idx] == nullptr) {
                curr->children[idx] = new TrieNode();
            }

            curr = curr->children[idx];
        }

        curr->word = word;
    }

    void dfs(vector<vector<char>>& board, int r, int c,
             TrieNode* node, vector<string>& result) {

        char ch = board[r][c];
        int idx = ch - 'a';

        if (node->children[idx] == nullptr) {
            return;
        }

        TrieNode* next = node->children[idx];

        if (next->word != "") {
            result.push_back(next->word);
            next->word = "";  // Avoid duplicate results
        }

        board[r][c] = '#';

        int rows = board.size();
        int cols = board[0].size();

        if (r > 0 && board[r - 1][c] != '#') {
            dfs(board, r - 1, c, next, result);
        }

        if (r + 1 < rows && board[r + 1][c] != '#') {
            dfs(board, r + 1, c, next, result);
        }

        if (c > 0 && board[r][c - 1] != '#') {
            dfs(board, r, c - 1, next, result);
        }

        if (c + 1 < cols && board[r][c + 1] != '#') {
            dfs(board, r, c + 1, next, result);
        }

        board[r][c] = ch;  // Backtrack
    }

public:
    vector<string> findWords(vector<vector<char>>& board,
                             vector<string>& words) {

        for (string& word : words) {
            insert(word);
        }

        vector<string> result;

        int rows = board.size();
        int cols = board[0].size();

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                dfs(board, i, j, root, result);
            }
        }

        return result;
    }
};
