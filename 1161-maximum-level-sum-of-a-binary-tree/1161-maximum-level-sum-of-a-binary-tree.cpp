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
    int maxLevelSum(TreeNode* root) {
        
        int maxSum = INT_MIN;
        int maxLvl = 0;
        int lvl = 1;

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()) {
            int n = q.size();

            int sum = 0;
            for(int i = 0; i < n; i++) {
                TreeNode* node = q.front();
                q.pop();

                sum += node->val;

                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }

            if(maxSum < sum) {
                maxSum = sum;
                maxLvl = lvl;
            }

            lvl++;
        }

        return maxLvl;
    }
};