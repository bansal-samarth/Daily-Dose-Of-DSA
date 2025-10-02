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
    ListNode* add(ListNode* l1, ListNode* l2, int carry) {
        int a = !l1 ? 0 : l1->val;
        int b = !l2 ? 0 : l2->val;

        if(!l1 && !l2 && carry == 0)
            return NULL;
        
        int n = a + b + carry;

        ListNode* num = new ListNode(n % 10);

        if(l1) l1 = l1->next;
        if(l2) l2 = l2->next;

        num->next = add(l1, l2, n / 10);

        return num;
    }

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

        return add(l1, l2, 0);
    }
};