class Solution {
public:
    string reverseWords(string s) {
        string final = "";
        int n = s.length();
        string t = "";

        for(int i =0; i<n; i++){
            if(s[i]==' ' && t.length()>0){
                if(final.length()>0)
                    final = t + +" "+ final;
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
    }
};