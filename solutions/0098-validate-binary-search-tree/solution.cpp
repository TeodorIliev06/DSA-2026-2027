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
    void inOrderDFS(TreeNode* root, vector<int>& result) {
        if(!root) {
            return;
        }

        inOrderDFS(root->left, result);
        result.push_back(root->val);
        inOrderDFS(root->right, result);
    }
    bool isValidBST(TreeNode* root) {
        vector<int> container;
        inOrderDFS(root, container);

        for(int i = 1; i < container.size(); i++) {
            if(container[i-1] >= container[i]) {
                return false;
            }
        }

        return true;
    }
};
