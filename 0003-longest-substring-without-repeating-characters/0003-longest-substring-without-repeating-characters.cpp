class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        set<char> st;
        int len = 0;
        int n = s.length();
        int maxLength = 0;
        int i = 0;
        int j = 0;

        while(i<n){
            if(st.find(s[i])==st.end()){
                len++;
                st.insert(s[i]);
                i++;
            }
            else{
                
                while(j<=i && st.find(s[i])!=st.end()){
                    st.erase(s[j]);
                    j++;
                    len--;
                }
                

            }
            maxLength = max(maxLength,len);
            
        }
        return max(maxLength,len);
    }
};