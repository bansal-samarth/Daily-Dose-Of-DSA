class Solution {
public:
    bool isValidBST(TreeNode* root) {
        return isBST(root, LONG_MIN, LONG_MAX);
    }

private:
    bool isBST(TreeNode* root, long min, long max)
    {
        if(!root)
            return true;
        
        if(!(root->val < max && root->val > min))
            return false;
        
        return isBST(root->left, min, root->val) && isBST(root->right, root->val, max);
    }
};

/*
class Solution {
public:
    bool check(vector<int> arr)
    {
        for(int i = 0 ; i < arr.size()-1; i++)
        {
            if(arr[i] >= arr[i+1])
                return false;
        }

        return true;
    }

    void Inorder(TreeNode* root, vector<int>& arr)
    {
        if(root)
        {
            Inorder(root->left, arr);
            arr.push_back(root->val);
            Inorder(root->right, arr);
        }
    }
    bool isValidBST(TreeNode* root) {
        vector<int> nums;
        Inorder(root, nums);
        return check(nums);
    }
};
*/