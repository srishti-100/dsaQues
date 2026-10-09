class Solution {
public:
    string reverseWords(string s) {
        /*
        string final = "";
        int n = s.length();
        string t = "";

        for(int i =0; i<n; i++){
            if(s[i]==' ' && t.length()>0){
                if(final.length()>0)
                    final = t +" "+ final;
                else
                    final = t;
                t = "";
            }
            if(s[i]!= ' '){
                t +=s[i];
            }
        }

        if(s[n-1]==' ')
            return final;
        if(final.length()>0)
            return t + " " +final;
        return t;
        */

        stringstream ss(s);

        string word;

        vector<string> words;
        string final ="";

        while( ss >> word){
            words.push_back(word);
        }

        reverse(words.begin(), words.end());

        for(int i = 0; i<words.size(); i++){
            if(final.length()>0){
                final = final+" " + words[i];
            }
            else{
                final = words[i];
            }
        }
        return final;
    }
};