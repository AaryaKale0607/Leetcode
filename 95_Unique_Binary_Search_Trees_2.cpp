#include <vector>
// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

using namespace std;

class Solution {
public:
      vector<TreeNode*> buildTrees(int start, int end) {
        vector<TreeNode*> trees;

        if (start > end) {
            trees.push_back(nullptr);
            return trees;
        }

        for (int rootVal = start; rootVal <= end; rootVal++) {
            vector<TreeNode*> leftTrees = buildTrees(start, rootVal - 1);
            vector<TreeNode*> rightTrees = buildTrees(rootVal + 1, end);

            for (auto left : leftTrees) {
                for (auto right : rightTrees) {
                    TreeNode* root = new TreeNode(rootVal);
                    root->left = left;
                    root->right = right;
                    trees.push_back(root);
                }
            }
        }

        return trees;
    }
    vector<TreeNode*> generateTrees(int n) {
          if (n == 0) return {};
        return buildTrees(1, n);
    }
};