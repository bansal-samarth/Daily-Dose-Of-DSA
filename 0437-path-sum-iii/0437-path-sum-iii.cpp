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
    int count = 0;

    void solve(TreeNode* root, long long sum, int target)
    {
        if(!root)
        {
            return ;
        }

        if(sum == target)
        {
            count++;
        }

        if(root->left)
            solve(root->left, sum + root->left->val, target);
        if(root->right)
            solve(root->right, sum + root->right->val, target);
    }

    void solution(TreeNode* root,int target)
    {
        if(root)
        {
            solution(root->left, target);
            solve(root, root->val, target);
            solution(root->right, target);
        }
    }

    int pathSum(TreeNode* root, int targetSum) {
        solution(root, targetSum);

        return count;
    }
};


/*
class Solution {
public:
    int search(TreeNode* root, int target, long long cur, unordered_map<long long, int>& mp){
        if (!root) return 0;
        cur += root->val;
        int c = mp[cur-target];
        mp[cur] ++;
        

        int left = search(root->left, target, cur, mp);
        int right = search(root->right, target, cur, mp);

        mp[cur] --;
        cur -= root->val;

        return c+left+right;

    }
    int pathSum(TreeNode* root, int targetSum) {
        long long cur = 0;
        unordered_map<long long, int> mp;
        mp[0] = 1;

        return search(root, targetSum, cur, mp);

    }
};
*/