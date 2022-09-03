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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        ListNode* temp= head;
        long long size=1;
        while(temp->next!=NULL){
            size ++;
            temp=temp->next;
        }
        if(size== n){
            head=head->next;
            return head;
        }
        temp= head;
        for(int i=1; i<(size-n+1)-1;i++){
            temp=temp->next;   
        }
        temp->next= temp->next->next;
        return head;
        
    }
};