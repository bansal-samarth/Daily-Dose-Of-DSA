/*
class Node {
  public:
    int data;
    Node *left;
    Node *right;

    Node(int x) {
        data = x;
        left = NULL;
        right = NULL;
    }
}; */

class Solution {
  public:
    void solve(Node* root, int k, int& maxi) {
        if(!root) return;
        
        if(root->data == k) {
            maxi = k;
            return;
        }
        
        if(root->data > k) {
            solve(root->left, k, maxi);
        }
        else {
            maxi = max(root->data, maxi);
            solve(root->right, k, maxi);
        }
    }
    int findMaxFork(Node* root, int k) {
        int ans = INT_MIN;
        solve(root, k, ans);
        
        return ans == INT_MIN ? -1 : ans;
    }
};