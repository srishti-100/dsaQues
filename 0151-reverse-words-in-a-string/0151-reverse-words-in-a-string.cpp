class Solution {
public:
    string reverseWords(string s) {
        int l = s.length();
        vector<string> vec;
        string ans;
        string t = "";
        for(int i = 0; i<l; i++){
            
            if(s[i]==' '){
                continue;
            }
            if(s[i]!=' '){
                t+=s[i];
            }
            if(i<l-1 && s[i]!= ' ' && s[i+1]==' '){
                vec.push_back(t);
                t = "";
            }
        }
        if(s[l-1]!=' '){
            vec.push_back(t);
        }

        for(int i = vec.size()-1; i>0; i--){
            ans+=vec[i]+ " ";
        }
        ans+=vec[0];
        return ans;
    }
};