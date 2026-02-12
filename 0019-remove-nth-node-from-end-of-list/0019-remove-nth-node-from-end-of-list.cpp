class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int k) {
        int n = 0;
        ListNode* temp = head;
        while(temp != NULL) {
            n++;
            temp = temp->next;
        }
        int move = n - k;
        ListNode* slow = head;
        ListNode* fast = head;
        while(move > 1) {
            slow = slow->next;
            fast = fast->next;
            move--;
        }
        if(n == k) {
            return head->next;
        }
        slow->next = slow->next->next;
        return head;
    }
};
    