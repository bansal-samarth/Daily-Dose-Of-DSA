/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        
        ListNode* p = headA;
        ListNode* q = headB;

        int n = 0;

        while(p != q) {
            p = p->next;
            q = q->next;

            if(!p) {
                p = headB;
                n++;
            }

            if(!q) q = headA;

            if(n == 2) return NULL;
        }

        return p;
    }
};