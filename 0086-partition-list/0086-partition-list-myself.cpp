class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode smallDummy(0), greatDummy(0); // Dummy nodes
        ListNode *smaller = &smallDummy, *greater = &greatDummy;

        while (head) {
            if (head->val < x) {
                smaller->next = head;
                smaller = smaller->next;
            } else {
                greater->next = head;
                greater = greater->next;
            }
            head = head->next;
        }

        greater->next = nullptr; // Ensure last node in greater list doesn't point to old nodes
        smaller->next = greatDummy.next; // Link smaller list to greater list

        return smallDummy.next; // Return new head
    }
};
