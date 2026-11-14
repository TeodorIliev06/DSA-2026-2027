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
    private:
    bool check(TreeNode* first, TreeNode* second) {
        if(!first && !second) {
            return true;
        }

        if(!first || !second) {
            return false;
        }

        return first->val == second->val &&
               check(first->left, second->right) &&
               check(first->right, second->left);
}
public:
    bool isSymmetric(TreeNode* root) {
        return check(root, root);
    }
};
