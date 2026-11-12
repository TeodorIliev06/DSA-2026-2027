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
    TreeNode* deleteNode(TreeNode* root, int val) {
        if(!root) {
            return nullptr;
        }

        if(root->val > val) {
            root->left = deleteNode(root->left, val);
        }
        else if(root->val < val) {
            root->right = deleteNode(root->right, val);
        }
        else {
            if(!root->left && !root->right) {
                return nullptr;
            }

            if(!root->left) {
                return root->right;
            }
            if(!root->right) {
                return root->left;
            }

            auto* iter = root->right;
            while(iter->left) {
                iter = iter->left;
            }

            root->val = iter->val;
            root->right = deleteNode(root->right, iter->val);
        }

        return root;
    }
};
