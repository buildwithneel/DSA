/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> res;
        vector<int> path;

        function<void(TreeNode*, int)> dfs = [&](TreeNode* node, int remaining) {
            if (!node) return;

            path.push_back(node->val);
            remaining -= node->val;

            if (!node->left && !node->right && remaining == 0) {
                res.push_back(path);
            } else {
                dfs(node->left, remaining);
                dfs(node->right, remaining);
            }

            path.pop_back();
        };

        dfs(root, targetSum);
        return res;
    }
};