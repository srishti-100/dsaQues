class Solution {
public:
    string reverseWords(string s) {
        int i = 0;
        int j = s.length()-1;
        while(s[i]==' ') i++;
        while(s[j]==' ') j--;
        stack<string> st;

        while(i<=j){
            string t ;
            while(i<=j && s[i]!=' '){
                t+=s[i];
                i++;
            }
            if(t.length()!=0)
                st.push(t);
            i++;
        }

        string ans;

        while(st.size()!=1){
            ans+=st.top();
            st.pop();
            ans+=' ';
        }

        ans+=st.top();

        return ans;

    }
};