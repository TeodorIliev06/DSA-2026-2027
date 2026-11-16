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
    int dfs(TreeNode* node, int& sum) {
        if(!node) {
            return 0;
        }

        int left = dfs(node->left, sum);
        int right = dfs(node->right, sum);

        sum = max(sum, left + right);

        return max(left, right) + 1;
    }

    int diameterOfBinaryTree(TreeNode* root) {
        if (!root) {
            return 0;
        }

        int sum = 0;
        dfs(root, sum);
        
        return sum;
    }
};
