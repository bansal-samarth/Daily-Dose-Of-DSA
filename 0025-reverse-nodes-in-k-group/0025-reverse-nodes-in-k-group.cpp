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
    ListNode* reverseKGroup(ListNode* head, int k) {
        
        ListNode* p = head;
        int len = 0;

        while(p) {
            len++;
            p = p->next;
        }

        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        ListNode* prev = dummy;

        while(len >= k) {
            ListNode* curr = prev;
            ListNode* nexx = curr->next;

            for(int i = 0; i < k; i++) {
                ListNode* temp = nexx->next;
                nexx->next = curr;
                curr = nexx;
                nexx = temp;
            }

            prev->next->next = nexx;
            ListNode* temp = prev->next;
            prev->next = curr;

            prev = temp;

            len -= k;
        }

        return dummy->next;
    }
};