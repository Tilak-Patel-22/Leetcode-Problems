/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        if(head == NULL)
            return head;
        dfs(head);
        return head;
    }
    
    Node* dfs(Node* head) {
        Node* curr = head;
        Node* last = NULL;
        
        while(curr != NULL) {
            Node* nextNode = curr->next;
            
            if(curr->child == NULL) {
                last = curr;
            } else {
                Node* childHead = curr->child;
                Node* childTail = dfs(childHead);
                
                curr->next = childHead;
                childHead->prev = curr;
                curr->child = NULL;
                
                if(nextNode != NULL) {
                    childTail->next = nextNode;
                    nextNode->prev = childTail;
                }
                
                last = childTail;
            }
            
            curr = nextNode;
        }
        
        return last;
    }
};