struct TrieNode{
    vector<TrieNode*> children;
    bool flag = false;

    TrieNode(){
        for(int i =0; i<26; i++){
            children.push_back(NULL);
        }
    }
};

class Trie {
private:
    TrieNode* root;
public:
    Trie() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* temp = root;
        for(int i = 0; i<word.length(); i++){
            int idx = word[i]-'a';

            if(temp->children[idx]==NULL){
                temp->children[idx] = new TrieNode();
            }
            temp = temp->children[idx];
        }
        temp->flag = true;
    }
    
    bool search(string word) {
        TrieNode* temp = root;
        for(int i = 0; i<word.length(); i++){
            int idx = word[i]-'a';

            if(temp->children[idx]!=NULL){
                temp = temp->children[idx];
            }
            else{
                return false;
            }
        }
        return (temp->flag == true);
    }
    
    bool startsWith(string prefix) {
        TrieNode* temp = root;
        for(int i = 0; i<prefix.length(); i++){
            int idx = prefix[i]-'a';

            if(temp->children[idx]!=NULL){
                temp = temp->children[idx];
            }
            else{
                return false;
            }
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */