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
    void inOrderDFS(TreeNode* root, vector<int>& container) {
        if (!root) {
            return;
        }

        inOrderDFS(root->left, container);
        container.push_back(root->val);
        inOrderDFS(root->right, container);
    }

    TreeNode* balance(vector<int> container, int left, int right) {
        if (left > right) {
            return nullptr;
        }

        int mid = left + (right - left) / 2;
        TreeNode* newRoot = new TreeNode(container[mid]);

        newRoot->left = balance(container, left, mid - 1);
        newRoot->right = balance(container, mid + 1, right);

        return newRoot;
    }

    TreeNode* balanceBST(TreeNode* root) {
        vector<int> container;

        inOrderDFS(root, container);

        return balance(container, 0, container.size() - 1);
    }
};
