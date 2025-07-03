/* Linked List Node structure:

struct Node
{
    int data;
    struct Node *next;
}

*/

class Solution {
  public:
    Node* reverseList(struct Node* head) {

        Node* p = head;
        Node* q = NULL;
        Node* r = NULL;
        
        while(p) {
            q = p;
            p = p->next;
            q->next = r;
            r = q;
        }
        
        return q;
    }
};