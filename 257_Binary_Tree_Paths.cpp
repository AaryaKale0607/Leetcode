#include<vector>
#include<string>
using namespace std;
// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    vector<string> ans;
    void dfs(TreeNode* root, string path) {

        if (root == nullptr) {
            return;
        }

        // Add current node to path
        if (!path.empty()) {
            path += "->";
        }

        path += to_string(root->val);

        // Check if current node is a leaf
        if (root->left == nullptr && root->right == nullptr) {
            ans.push_back(path);
            return;
        }

        // Explore left and right subtrees
        dfs(root->left, path);
        dfs(root->right, path);
    }

    vector<string> binaryTreePaths(TreeNode* root) {
        ans.clear();

        dfs(root, "");

        return ans;
    }
};