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
    ListNode* reverseList(ListNode* head) {

        //tc: O(N) SC: O(N)
        /*
        if(head == NULL) return head;
        ListNode* h = NULL;
        ListNode* t = NULL;
        //ListNode* s = NULL;
        ListNode* temp = head;

        while(temp!=NULL){
            if(h == NULL) {
                h = temp;
                t = temp;
                temp = temp->next;
                t->next = NULL;
                continue;
            }
            else{
                ListNode* r = temp;
                temp = temp->next;
                
                r->next = h;
                h = r;
            }
            
        }

        return h;
        */

        //

        if(head == NULL) return NULL;
   ListNode* prev = NULL;
    ListNode* curr = head;
    ListNode* nxt = head->next;

    while(curr!=NULL){
        curr->next = prev;
        prev = curr;
        curr = nxt;
        if(curr!=NULL)
            nxt = curr->next;

    }
    return prev;
        
    }
};