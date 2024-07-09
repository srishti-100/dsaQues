class Solution {
public:
    string reversePrefix(string word, char ch) {
        int pos = (word.find(ch)!=string::npos)?word.find(ch):-1;

        if(pos == -1){
            return word;
        }
        else{
            int i =0;
            int j = pos;
            while(i<=j){
                char p = word[j];
                word[j] = word[i];
                word[i] = p;
                i++;
                j--; 
            }
        }
        return word;
    }
};