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
    bool isPalindrome(ListNode* head) {
        if(head==NULL || head->next==NULL){
            return true;
        }
        //finding middle
        ListNode* slow=head,*fast=head;
        while(fast->next!=NULL && fast->next->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        slow->next=reverseList(slow->next);
        slow=slow->next;
        ListNode* dummy= head;
        while(slow!=NULL){
            if(dummy->val!=slow->val){
                return false;
            }
            slow=slow->next;
            dummy=dummy->next;
        }
        return true; 
    }
    ListNode* reverseList(ListNode* head){
        ListNode* prev=NULL,*nex=NULL;
        while(head!=NULL){
            nex=head->next;
            head->next=prev;
            prev=head;
            head=nex;     
        }
        return prev;
    }
};