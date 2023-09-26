class Solution {
public:
    string removeDuplicateLetters(string s) {
        unordered_map<char,int> mp;
        unordered_set<char> sts;
        stack<char> st;


        for(int i =0; i<s.length(); i++){
            mp[s[i]] = i;
        }

        for(int i =0; i<s.length(); i++){
            char c = s[i];

            if(sts.find(s[i])==sts.end()){
                while(!st.empty() && c<st.top() && i<mp[st.top()]){
                    sts.erase(st.top());
                    st.pop();
                }
                sts.insert(c);
                st.push(c);
            }
           
        }


        string res;
        while(!st.empty()){
            res=st.top()+res;
            st.pop();
        }
        return res;
    }
};