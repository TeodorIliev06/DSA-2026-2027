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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(!root) {
            return {};
        }

        queue<TreeNode*> queue;
        queue.push(root);
        vector<vector<int>> result;
        while(!queue.empty()) {
            vector<int> level;

            auto size = queue.size();
            for(int i = 0; i < size; i++) {
                auto* currNode = queue.front();
                queue.pop();
                level.push_back(currNode->val);

                if(currNode->left) {
                    queue.push(currNode->left);
                }
                if(currNode->right) {
                    queue.push(currNode->right);
                }
            }

            result.push_back(level);
        }

        return result;
    }
};
