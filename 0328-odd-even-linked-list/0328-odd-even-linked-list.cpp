/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        ListNode* evenHead = new ListNode(0);
        ListNode* oddHead = new ListNode(0);

        ListNode* even = evenHead;
        ListNode* odd = oddHead;

        ListNode* p = head;
        while(p) {
            odd->next = new ListNode(p->val);
            odd = odd->next;
            p = p->next;

            if(!p) continue;

            even->next = new ListNode(p->val);
            even = even->next;
            p = p->next;
        }

        odd->next = evenHead->next;
        return oddHead->next;
    }
};