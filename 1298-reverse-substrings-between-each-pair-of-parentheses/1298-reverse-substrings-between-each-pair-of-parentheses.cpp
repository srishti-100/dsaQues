class Solution {
public:
    string reverseParentheses(string s) {
        stack<int> st;
        string res="";

        for(int i =0; i<s.length(); i++){
            if(s[i]=='('){
                st.push(res.size());
            }
            else if (s[i] <='z' && s[i]>='a'){
                res+=s[i];
            }
            else{
                int idx = st.top();
                st.pop();
                reverse(res.begin() + idx , res.end());
                
            }
        }
        return res;
    }
};