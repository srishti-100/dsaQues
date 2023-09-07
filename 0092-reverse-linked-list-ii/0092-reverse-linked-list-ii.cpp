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
private:
    pair<ListNode*,ListNode*> reverse(ListNode* head, int length) {
        ListNode* temp = head;
        ListNode* h = NULL;
        ListNode* t = NULL;

        while(length!=0 && temp!=NULL){
            ListNode* newNode = new ListNode(temp->val);
            if(h == NULL){
                h = newNode;
                t = newNode;
            }
            else{
                newNode->next = h;
                h = newNode;
            }
            length--;
            temp = temp->next;
        }

        return {h,t};
    }
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(left==right) return head;

        int n = 0;
        ListNode* temp = new ListNode(-1);
        ListNode* prev = temp;
        temp->next = head;
        while(n<left-1){
            prev = prev->next;
            n++;
        }
        ListNode* curr = prev->next;
        pair<ListNode*, ListNode*> p = reverse(curr, right-left+1);
        ListNode* prev2= curr;
        int i = 0;
        while(i<right-left+1){
            prev2 = prev2->next;
            i++;
        }

        prev->next = p.first;
        p.second->next = prev2;
        return temp->next;


    }
};