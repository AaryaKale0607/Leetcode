#include <string>
using namespace std;
class WordDictionary {
private:
    struct TrieNode {
        TrieNode* children[26];
        bool isEnd;

        TrieNode() {
            for (int i = 0; i < 26; i++) {
                children[i] = nullptr;
            }
            isEnd = false;
        }
    };

    TrieNode* root;

    bool dfs(string& word, int index, TrieNode* node) {
        if (index == word.size()) {
            return node->isEnd;
        }

        char ch = word[index];

        if (ch == '.') {
            for (int i = 0; i < 26; i++) {
                if (node->children[i] != nullptr &&
                    dfs(word, index + 1, node->children[i])) {
                    return true;
                }
            }
            return false;
        }

        int idx = ch - 'a';

        if (node->children[idx] == nullptr) {
            return false;
        }

        return dfs(word, index + 1, node->children[idx]);
    }
public:
    WordDictionary() {
        root = new TrieNode(); 
    }
    
    void addWord(string word) {
         TrieNode* curr = root;

        for (char ch : word) {
            int idx = ch - 'a';

            if (curr->children[idx] == nullptr) {
                curr->children[idx] = new TrieNode();
            }

            curr = curr->children[idx];
        }

        curr->isEnd = true;
    }
    
    bool search(string word) {
         return dfs(word, 0, root);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */