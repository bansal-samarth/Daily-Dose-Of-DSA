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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        ListNode* fast = head;
        ListNode* slow = head;

        for(int i = 1; i < n; i++)
            fast = fast->next;

        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* p = dummy;

        while(fast->next) {
            fast = fast->next;
            p = p->next;
        }

        p->next = p->next->next;

        return dummy->next;
    }
};