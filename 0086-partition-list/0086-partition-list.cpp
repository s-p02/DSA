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
    ListNode* partition(ListNode* head, int x) {
        ListNode* dummy1= new ListNode(0);
        ListNode* temp= head;
        ListNode* temp1= dummy1;
        while(temp){
            if(temp->val <x){
                ListNode* dummy= new ListNode(temp->val);
                temp1->next= dummy;
                temp1=temp1->next;
            }
            temp= temp->next;
        }
        
        ListNode* dummy2= new ListNode(0);
        ListNode* temp2= dummy2;
        temp= head;
        while(temp){
            if(temp->val >=x){
                ListNode* dummy= new ListNode(temp->val);
                temp2->next= dummy;
                temp2=temp2->next;
            }
            temp= temp->next;
        }
        temp2->next= NULL;
        dummy2=dummy2->next;
        temp1->next= dummy2;
        return dummy1->next;
        
    }
};