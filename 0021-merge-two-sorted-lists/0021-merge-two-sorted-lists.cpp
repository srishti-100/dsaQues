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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* t1 = list1;
        ListNode* t2 = list2;
        if(t1==NULL) return t2;
        if(t2==NULL) return t1;
        ListNode* h = NULL;
        ListNode* t = NULL;

        while(t1!=NULL && t2!=NULL){
            if(h == NULL){
                if(t1->val <= t2->val){
                    h = t1;
                    t = t1;
                    t1 = t1->next;
                }
                else{
                    h =t2;
                    t = t2;
                    t2=t2->next;
                }
        
            }
            else{
                if(t1->val <= t2->val){
                    
                    t->next = t1;
                    t = t->next;
                    t1 = t1->next;
                }
                else{
                    t->next = t2;
                    t=t->next;
                    t2 = t2->next;
                }
            }
        }
        if(t1 == NULL){
            t->next = t2;
        }
        else
            t->next = t1;
    
        return h;

    }
};