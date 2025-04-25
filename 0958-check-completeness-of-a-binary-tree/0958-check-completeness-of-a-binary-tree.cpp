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
    bool isCompleteTree(TreeNode* root) {
        bool nullSeen = false;

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()) {
            int n = q.size();

            for(int i = 0; i < n; i++) {
                TreeNode* node = q.front();
                q.pop();

                if(node->left && nullSeen) {
                    return false;
                } else if(node->left) {
                    q.push(node->left);
                } else {
                    nullSeen = true;
                }

                if(node->right && nullSeen) {
                    return false;
                } else if(node->right) {
                    q.push(node->right);
                } else {
                    nullSeen = true;
                }
            }
        }

        return true;
    }
};