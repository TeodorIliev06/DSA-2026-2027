/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    pair<int, TreeNode*> postOrder(TreeNode* node) {
        if (!node) {
            return {0, nullptr};
        }

        auto [leftHeight, leftLCA] = postOrder(node->left);
        auto [rightHeight, rightLCA] = postOrder(node->right);

        if (leftHeight > rightHeight) {
            return {leftHeight + 1, leftLCA};
        } else if (rightHeight > leftHeight) {
            return {rightHeight + 1, rightLCA};
        }

        return {leftHeight + 1, node};
    }

    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        if (!root) {
            return nullptr;
        }

        return postOrder(root).second;
    }
};
