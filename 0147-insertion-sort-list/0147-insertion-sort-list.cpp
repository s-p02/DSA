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
    ListNode* insertionSortList(ListNode* head) {
        
        ListNode* l= head;
        if(head->next==NULL){
            return head;
        }
        ListNode* r= l->next;
        
        while(r!=NULL){
            ListNode* t1= head;
            ListNode* t2=t1->next;
            if(l->val>r->val){
                if(r->val<t1->val){
                    l->next=r->next;
                    r->next=head;
                    head= r;
                }
                else{
                    while(r->val>t2->val){
                        t1=t1->next;
                        t2=t2->next;
                    }
                    l->next= r->next;
                    r->next=t2;
                    t1->next=r;
                }
                 r=l->next;
            }
            else{
                l=l->next;
                r=r->next;
            }
        }
        
        return head;
        
    }
};