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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if (!root) {
            return {};
        }

        vector<vector<int>> result;
        int level = 0;
        bool leftRight = true;
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            int size = q.size();
            vector<int> levelResult(size);
            for (int i = 0; i < size; i++) {
                auto* currNode = q.front();
                q.pop();
                
                int index = leftRight ? i : size - 1 - i;
                levelResult[index] = currNode->val;
                if (currNode->left) {
                    q.push(currNode->left);
                }
                if (currNode->right) {
                    q.push(currNode->right);
                }
            }

            level++;
            leftRight = !leftRight;
            result.push_back(levelResult);
        }

        return result;
    }
};
