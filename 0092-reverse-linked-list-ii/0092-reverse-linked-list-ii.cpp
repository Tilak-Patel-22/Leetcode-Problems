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

 
/**Pehle ek vector banaya kyunki linked list ke elements ko easily reverse kar sake.
while loop se puri linked list traverse karke saari values vector mein store ki.
Fir left se right tak vector ka requried part reverse kar denge. 
Uske baad dobara linked list par loop chalaya aur reversed vector ki values node mai vapis daal di.
finally head return kar diya. **/

class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        vector<int> arr;
        ListNode* temp = head;
        while (temp != NULL) {
            arr.push_back(temp->val);
            temp = temp->next;
        }
        reverse(arr.begin() + left - 1, arr.begin() + right);
        temp = head;
        for (int i = 0; i < arr.size(); i++) {
            temp->val = arr[i];
            temp = temp->next;
        }
        return head;
    }
};