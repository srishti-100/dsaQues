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
    int pairSum(ListNode* head) {
        if(head==NULL ) return 0;
        
        stack<ListNode*> st;

        ListNode* temp = head;
        while(temp!=NULL){
            st.push(temp);
            temp = temp->next;
        }

        temp = head;
        int maxSum = 0;

        while(temp!=NULL){
            int sum = temp->val + st.top()->val;
            maxSum = max(maxSum,sum);
            st.pop();
            temp = temp->next;
        }
        return maxSum;
    }
};