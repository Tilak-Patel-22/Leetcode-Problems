/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
void Insert(Node* head){
    Node* temp=head;
    while(temp!=NULL){
        Node* next=temp->next;
        Node* copy=new Node(temp->val);
        temp->next=copy;
        copy->next=next;
        temp=next;
    }
}
void connectRandom(Node* head){
    Node* temp=head;
    while(temp!=NULL){
        if(temp->random) temp->next->random=temp->random->next;
        temp=temp->next->next;
    }
}
Node* deepCopy(Node* head){
    Node* dummy=new Node(0);
    Node* tail=dummy;
    Node* temp=head;
    while(temp!=NULL){
        Node* copy=temp->next;
        Node* next=copy->next;
        tail->next=copy;
        tail=copy;
        temp->next=next;
        temp=next;
    }
    return dummy->next;
}
Node* copyRandomList(Node* head){
    if(head==NULL) return NULL;
    Insert(head);
    connectRandom(head);
    return deepCopy(head);
}
};
