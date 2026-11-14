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
    vector<int> rightSideView(TreeNode* root) {
        if(!root) {
            return {};
        }

        vector<int> result;
        queue<TreeNode*> queue;
        queue.push(root);

        while(!queue.empty()) {
            auto size = queue.size();

            for(int i = 0; i < size; i++){
                auto* currentNode = queue.front();
                queue.pop();

                if(currentNode->left) {
                    queue.push(currentNode->left);
                }
                if(currentNode->right) {
                    queue.push(currentNode->right);
                }
                if(i == size - 1) {
                    result.push_back(currentNode->val);
                }
            }
        }

        return result;
    }
};
