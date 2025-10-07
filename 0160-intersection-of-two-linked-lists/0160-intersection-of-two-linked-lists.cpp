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
        
        ListNode* a = headA;
        ListNode* b = headB;
        int cnt = 0;

        while(a != b) {
            a = a->next;
            b = b->next;

            if(!a) {
                a = headB;
                cnt++;
            }

            if(!b) {
                b = headA;
                cnt++;
            }

            if(cnt > 2) return NULL;
        }

        return a;
    }
};