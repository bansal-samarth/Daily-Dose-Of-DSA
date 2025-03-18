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
    ListNode* partition(ListNode* head, int x) {
        if(!head) return NULL;

        ListNode* small = new ListNode(0);
        ListNode* smaller = small;

        ListNode* great = new ListNode(0);
        ListNode* greater = great;

        ListNode* p = head;
        while(p) {
            if(p->val < x) {
                smaller->next = p;
                p = p->next;
                smaller = smaller->next;
                smaller->next = NULL;
            } else {
                greater->next = p;
                p = p->next;
                greater = greater->next;
                greater->next = NULL;
            }
        }

        if(!small->next || !great->next) return head;

        head = small->next;

        smaller->next = great->next;

        return head;
    }
};