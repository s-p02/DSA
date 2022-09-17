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
    Node* copyRandomList(Node* head) {
        unordered_map<Node*,Node*> originalToCopy;
        Node* ptr=head;
        while(ptr!=NULL){
            Node* newNode= new Node(ptr->val);
            originalToCopy[ptr]=newNode;
            ptr=ptr->next;
        }
        ptr=head;
        while(ptr!=NULL){
            originalToCopy[ptr]->next=originalToCopy[ptr->next];
            originalToCopy[ptr]->random= originalToCopy[ptr->random];
            ptr=ptr->next;
        }
        return originalToCopy[head];
    }
};