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
    TreeNode* succ(TreeNode* root) {
        TreeNode* node = root->left;

        while(node->right) {
            node = node->right;
        }

        return node;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root) return NULL;
        
        if(root->val > key) {
            root->left = deleteNode(root->left, key);
        } else if(root->val < key) {
            root->right = deleteNode(root->right, key);
        } else {
            if(!root->left)
                return root->right;
            if(!root->right)
                return root->left;
            
            TreeNode* temp = succ(root);
            root->val = temp->val;
            root->left = deleteNode(root->left, temp->val);
        }

        return root;
    }
};