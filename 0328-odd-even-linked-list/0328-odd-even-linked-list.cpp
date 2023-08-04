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
    ListNode* oddEvenList(ListNode* head) {
        if(head==NULL || head->next==NULL || head->next->next==NULL) return head; 
        ListNode* nh = NULL;
        ListNode* nt = NULL;
        ListNode* temp = head;
        ListNode* n = head->next;

        while(n!=NULL && n->next!=NULL){
            if(nh==NULL){
                nh=n;
                nt=n;
            }
            else{
                nt->next = n;
                nt = n;
            }
            temp->next = n->next;
            temp = temp->next;
            n=temp->next;
        }
        
        if(n!=NULL){
            nt->next = n;
            nt = nt->next;
        }
        nt->next = NULL;
        temp->next = nh;

        return head;

    }
};