class Solution {
    /*
private:
    bool countDifference(string t,string r){
        int count = 0;
        for(int i =0; i<t.length(); i++){
            if(t[i]!=r[i]) count++;
        }
        return (count==1)?true:false;
    }

    void helper(string s, string endWord, vector<string>& wordList, vector<string>& visited, int words, int& minWords){
        if(s == endWord) return;
        visited[s]=1;

        for(int i =0; i<wordList; i++){
            if(!visited[i]){
                if(countDifference(s,wordList[i])){
                    words++;
                    helper(wordList[i],endWord, wordList, visied, words, minWords);
                    minWords = min(words,minWords);
                }
            }
            
        }
        
    }

public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int minWords = INT_MAX;
        int words = 0;
        int n = wordList.size();
        vector<string> visited(n,0);
        helper(beginWord,endWord,wordList,visited,words, minWords);

        if(minWords == INT_MAX) return 0;

        return minWords;
    }
    */
    public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {

        bool found = false;
        set<string> words(wordList.begin(), wordList.end());
        int length = 0;
        queue<pair<string,int>> q;
        q.push({beginWord,1});

        while(!q.empty()){
            string s = q.front().first;
            int w = q.front().second;
            q.pop();
            if(s==endWord){ 
                found=true;
                length = w;
            }

            for(int i =0; i<s.length(); i++){
                char original = s[i];
                for(char j = 'a'; j<='z'; j++){
                    s[i]=j;
                    if(words.find(s)!=words.end()){
                        q.push({s,w+1});
                        words.erase(s);
                    }
                }   
                s[i]=original;               
            }

        }

        if(found == false)
            return 0;

        return length;


    }

};