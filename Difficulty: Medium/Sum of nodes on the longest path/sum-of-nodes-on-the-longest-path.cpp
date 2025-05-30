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
    void solve(Node* root, unordered_map<int,int>& map, int sum, int lvl) {
        if(!root) return;
        
        sum += root->data;
        map[lvl] = max(map[lvl], sum);
        
        
        solve(root->left, map, sum, lvl + 1);
        solve(root->right, map, sum, lvl + 1);
    }
    int sumOfLongRootToLeafPath(Node *root) {
        unordered_map<int,int> map;
        
        solve(root, map, 0, 1);
        
        int size = map.size();
        
        return map[size];
    }
};