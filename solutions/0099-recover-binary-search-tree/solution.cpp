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
    void inOrderDFS(TreeNode* root, TreeNode*& first, TreeNode*& second, TreeNode*& prev) {
        if(!root) {
            return;
        }

        inOrderDFS(root->left, first, second, prev);

        if(prev && prev->val > root->val) {
            if(!first) {
                first = prev;
            }

            second = root;
        }
        prev = root;

        inOrderDFS(root->right, first, second, prev);
    }
    void recoverTree(TreeNode* root) {
        TreeNode* prev = nullptr;
        TreeNode* first = nullptr;
        TreeNode* second = nullptr;

        inOrderDFS(root, first, second, prev);

        if(first && second) {
            swap(first->val, second->val);
        }
    }
};
