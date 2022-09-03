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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        
        if(l1 == NULL) return l2; 
        if(l2 == NULL) return l1;
        // here dummy->next will serve as the head of the new LinkedList
        ListNode* dummy = new ListNode(0);
        
        // creating a temp node to traverse the newList
        ListNode* temp= dummy;
        
        while(l1 && l2){
            if(l1->val<= l2->val){
                ListNode* newNode = new ListNode(l1->val);
                l1=l1->next;
                temp->next= newNode;
                temp= temp->next; 
            }
            else{
                ListNode* newNode = new ListNode(l2->val);
                l2=l2->next;
                temp->next= newNode;
                temp= temp->next;
            }
        }
        while(l1){
            ListNode* newNode = new ListNode(l1->val);
            l1=l1->next;
            temp->next= newNode;
            temp= temp->next; 
        }
        
        while(l2){
            ListNode* newNode = new ListNode(l2->val);
            l2=l2->next;
            temp->next= newNode;
            temp= temp->next;  
        }
        
        ListNode* newHead= dummy->next;
        return newHead;     
    }
};