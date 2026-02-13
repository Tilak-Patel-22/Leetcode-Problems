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
    ListNode* rotateRight(ListNode* head, int k) {
         if(head==nullptr || head->next==nullptr || k==0){
            return head;
         }
         for(int i=0; i<k; i++){
            ListNode* curr = head;
            ListNode* prev = nullptr;
            while(curr->next != nullptr){
            prev = curr;
            curr=curr->next;
            }
            prev->next = nullptr;
            curr->next=head;
            head=curr;
         } 
         return head;
    }
};