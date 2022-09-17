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

        // First round: make copy of each node,
        // and link them together side-by-side in a single list.
        Node* itr= head;
        Node* front= head;
        while(itr != NULL){
            front =itr->next;
            Node * newNode= new Node(itr->val);
            itr->next=newNode;
            newNode->next=front;
            itr=front;
        }
        
        // assign random pointers for the copy nodes.
        
        itr=head;
        while(itr!=NULL){
            if(itr->next!=NULL){
               if(itr->random!=NULL){
                    itr->next->random=itr->random->next;
               }  
            }
            itr=itr->next->next;
        }
        
        // restore the original list, and extract the copy list.
        itr=head;
        Node* dummy = new Node(0);
        Node* temp=dummy;
        while(itr!=NULL){
            dummy->next= itr->next;
            dummy=dummy->next;
            itr->next= itr->next->next;
            itr=itr->next;
        }
        
        return temp->next;
        
    }
};