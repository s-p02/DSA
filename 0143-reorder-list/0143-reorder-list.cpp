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
    
    ListNode* reverse(ListNode* head) {
        ListNode* prev= NULL;
        ListNode* current= head;
        ListNode* next_p;
        
        while(current!=NULL){
            next_p= current->next;
            current-> next= prev;
            prev= current;
            current= next_p;
        }
        head= prev;
        return head;
    }
    
    void reorderList(ListNode* head) {
        int n=0;
        ListNode* temp= head;
        while(temp!=NULL){
            n++;
            temp=temp->next;
        }
        
        temp=head;
        int i=1;
        while(i<n/2){
            temp=temp->next;
            i++;
        }
        
        ListNode* temp2= temp->next;
        temp->next=NULL;
        
        ListNode* head2= reverse(temp2);
        
        ListNode* head1= head;
        ListNode* dummy= new ListNode(0);
        temp=dummy;
        while(head1 && head2){
            temp->next=head1;
            head1=head1->next;
            temp= temp->next;
            temp->next= head2;
            head2=head2->next; 
            temp=temp->next;
        }
        while(head1){
            temp->next=head1;
            head1=head1->next;
            temp= temp->next;
        }
        while(head2){
            temp->next= head2;
            head2=head2->next; 
            temp=temp->next;
        }
        return ;
    }
};