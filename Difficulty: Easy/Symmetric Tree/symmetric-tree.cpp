/*
class Node {
public:
    int data;
    Node *left, *right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};
*/
class Solution {
  public:
    bool isValid(Node* root1, Node* root2) {
        if(!root1 && !root2)
            return true;
        if(!root1 || !root2)
            return false;
            
        if(root1->data != root2->data)
            return false;
        
        return isValid(root1->left, root2->right) && isValid(root1->right, root2->left);
    }
    bool isSymmetric(Node* root) {
        return isValid(root->left, root->right);
    }
};