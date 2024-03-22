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
    ListNode* helper(ListNode* head){
    ListNode* prev= NULL;
    ListNode* n = NULL;
    ListNode* curr = head;

    while(curr!=NULL){
        n = curr->next;
        curr->next = prev;
        prev = curr;
        curr = n;
    }
    return prev;
}
    
    bool isPalindrome(ListNode* head) {
        ListNode* f = head;
        ListNode* s = head;
        ListNode* temp = head;
        while(f->next!=NULL && f->next->next!=NULL){
            f = f->next->next;
            s = s->next;
        }

        ListNode* h2 = helper(s->next);

        while(h2!=NULL){
            if(temp->val!=h2->val) return false;
            h2 = h2->next;
            temp= temp->next;
        }

        return true;
    }
};