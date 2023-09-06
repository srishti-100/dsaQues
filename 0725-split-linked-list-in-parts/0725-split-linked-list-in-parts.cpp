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
    int length(ListNode* head){
        int l =0;
        while(head!=NULL) {
            l++;
            head = head->next;
        }
        return l;
    }
    /*
public:
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        vector<ListNode*> ans;
        int l = length(head);

        int part = l/k;
        int rem = l%k;

        ListNode* t = head;
        while(t!=NULL){
            ListNode* h = t;
            if(rem!=0){
                int i =0;
                while(i<part){
                    t = t->next;
                    i++;
                }
                rem--;
            }
            else{
                int i =0;
                while(i<part-1){
                    t = t->next;
                    i++;
                }
            }
            ListNode* temp = t->next;
            t->next = NULL;
            ans.push_back(h);
            t = temp;
        } 
        if(part ==0){
            if(ans.size()<k){
                while(ans.size()!=k){
                    ans.push_back(NULL);
                }
            }
        }
        return ans;
    }*/
    public:
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        vector<ListNode*> ans;
        int l = length(head);

        int part = l/k;
        int rem = l%k;
        ListNode* temp = head;
        for(int i =0; i<k; i++){
            ListNode* h = temp;
            for(int j = 0; j<part +(rem>0?0:-1); j++){
                temp = temp->next;
            }
            rem--;
            if(temp!=NULL){
                ListNode* t = temp->next;
                temp->next = NULL;
                
                temp = t;
            }
            ans.push_back(h);

        }
        return ans;
    
    }

};