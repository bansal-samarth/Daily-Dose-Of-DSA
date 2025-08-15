/*
class Node {
  public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = nullptr;
    }
};
*/
class Solution {
  public:
    void removeLoop(Node* head) {
        Node* slow = head;
        Node* fast = head;
        
        while(fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            
            if(slow == fast) {
                slow = head;
                
                while(fast != slow) {
                    slow = slow->next;
                    fast = fast->next;
                }
                
                while(fast->next != slow)
                    fast = fast->next;
                
                fast->next = NULL;
                
                return;
            }
        }
        
        return;
    }
};