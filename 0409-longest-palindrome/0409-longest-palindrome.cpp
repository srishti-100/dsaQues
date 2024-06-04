class Solution {
public:
    int longestPalindrome(string s) {
        int len = 0;
        unordered_set<char> st;

        for(int i =0; i<s.length(); i++){
            if(st.find(s[i])==st.end()){
                st.insert(s[i]);
            }
            else{
               st.erase(s[i]);
               len+=2;
            }
        }
        if(st.empty()){
            return len;
        }
        return len+1;
    }
};