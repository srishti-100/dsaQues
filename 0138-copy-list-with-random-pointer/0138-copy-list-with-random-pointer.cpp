/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* prev = NULL;
        unordered_map<Node*,Node*> mp;

        Node* temp = head;
        while(temp!=NULL){
            Node* n = new Node(temp->val);
            mp[temp] = n;
            if(prev==NULL){
                prev=n;
            }
            else{
                prev->next = n;
                prev= n;
            }
            temp=temp->next;
        }

        //random pointer set up
        Node* temp2 = head;
        //jo current node h uska random dekhenge usko ek variable m store kr denge
        //ab map m current node k corresponding node dhundhemge aur uske random m mp[r] ko set kr denge

        while(temp2!=NULL){
            if(temp2->random!=NULL){
                Node* r = temp2->random;
                Node*curr = mp[temp2];
                curr->random = mp[r];
            }
            temp2 = temp2->next;
        }

        return mp[head];
    }
};