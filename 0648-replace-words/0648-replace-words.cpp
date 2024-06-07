class TrieNode{
        public:
        TrieNode* children[26];
        bool isEnd;

        TrieNode(){
            isEnd = false;
            for(int i =0; i<26; i++){
                children[i]=nullptr;
            }
        }
};

class Trie{
    TrieNode* root;
    public:
    Trie(){
        root = new TrieNode();
    }

    void insert(string word){
        TrieNode* node = root;

        for(char ch:word){
            if(node->children[ch-'a']==nullptr){
                node->children[ch-'a'] = new TrieNode();
            }
            node = node->children[ch-'a'];
        }
        node->isEnd = true;
    }

    string search(string word){
        TrieNode* node = root;

        string result;

        for(char ch:word){
            if(node->children[ch-'a']==nullptr){
                return word;
            }
            result+=ch;
            if(node->children[ch-'a']->isEnd){
                return result;
            }
            node= node->children[ch-'a'];
        }
        return word;
    }
};

class Solution {
public:
//trie is the optimal approach for solving this problem 
//hash set is not the optimal way

    /*
    static bool compString ( string& a, string& b){
        if(a.length()<b.length()){
            return true;
        }
        return false;
    }
    string replaceWords(vector<string>& d, string s) {

        stringstream ss(s);
        string ans = "";
        string word = "";
        sort(d.begin(),d.end(),compString);
        while(ss>>word){
            bool replaced = false;
            for(auto str: d){
                if(word.find(str)==0){ // jo word ko replace krnaa h voh staring index pe h ki nhi
                                      // find function returns the index of first occurence of the string
                    ans+=str+ " ";
                    replaced = true;
                    break;
                }
            }
            if(!replaced){
                ans+=word+" ";
            }

        }
        if(ans.length()){
            ans.pop_back();
        }
        return ans;
    }
    */
    

    string replaceWords(vector<string>& d, string s) {
        Trie trie;
        for(string word: d){
            trie.insert(word);
        }

        stringstream ss(s);
        string result,word;
        
        while(ss>>word){
            string pref = trie.search(word); 
            if(!pref.empty()){
                result+=pref+" ";
            }
            else{
                result+=word+" ";
            }
        }
        if(!result.empty()){
            result.pop_back();
        }
        return result;
    }

};