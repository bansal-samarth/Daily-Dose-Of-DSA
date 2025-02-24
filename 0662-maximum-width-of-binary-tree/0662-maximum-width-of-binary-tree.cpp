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
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});
        int maxi = 1;

        while(!q.empty()) {
            int n = q.size();

            // To Prevent OverFlow
            int mmin = q.front().second;
            int first, last;

            for(int k = 0; k < n; k++) {
                TreeNode* node = q.front().first;
                int curr = q.front().second - mmin;
                q.pop();

                if(k == 0) first = curr;
                if(k == n-1) last = curr;

                if(node->left) q.push({node->left, 2*curr+1});
                if(node->right) q.push({node->right, 2*curr+2});
            }

            maxi = max(maxi, last - first + 1);
        }

        return maxi;
    }
};