// this approach leads to tle!!!

class Solution {
    void getCount(string str, string sub, int& cnt1, int& cnt2) {
    
        char first = sub[0], second = sub[1];
        int i = 1;
        while(i < str.length()) {
            if(i > 0 && str[i-1] == first && str[i] == second) {
                cnt1++;
                str.erase(i-1, 2);
                i--;
                continue;
            }
            i++;
        }

        i = 1;
        while(i < str.length()) {
            if(i > 0 && str[i-1] == second && str[i] == first) {
                cnt2++;
                str.erase(i-1, 2);
                i--;
                continue;
            }
            i++;
        }
        return;
    }
public:
    int maximumGain(string s, int x, int y) {
        
        int mxABcnt = 0;
        int mxBAcnt = 0;
        int minBAcnt = 0;
        int minABcnt= 0;

        getCount(s, "ab", mxABcnt, minBAcnt);
        getCount(s, "ba", mxBAcnt, minABcnt);

        int operation1 = mxABcnt * x + minBAcnt * y;
        int operation2 = mxBAcnt * y + minABcnt * x;
        return max(operation1, operation2);
    }
};

/*
since the above approach uses find and erase function multiple times, and these
functions themselves have linear time complexity
hence repeated calling of these functions within a loop could lead to tle
*/

/*
to optimise our solution we can use stack based approach
that will pass the string in one pass
*/

// class Solution{
//  public:
//     int maximumGain(string s, int x, int y) {
//         stack<char> st;
//         stack<char> stemp;
//         st.push(s[0]);
//         int ans = 0;

//         if(y>x){
//             for(int i =1; i<s.length(); i++){
//                 if(st.top()=='b' && s[i]=='a'){
//                     st.pop();
//                     ans+=y;
//                 }
//                 else{
//                     st.push(s[i]);
//                 }
//             }

//             st = stemp;
//             if(s.length()>=2){
//                 st.push(s[0]);
//             }
//             for(int i =1; i<s.length(); i++){
//                 if(st.top()=='a'&& s[i]=='b'){
//                     st.pop();
//                     ans+=x;
//                 }
//                 else{
//                     st.push(s[i]);
//                 }
//             }
//         }
//         else{
//             for(int i =1; i<s.length(); i++){
//                 if(st.top()=='a' && s[i]=='b'){
//                     st.pop();
//                     ans+=x;
//                 }
//                 else{
//                     st.push(s[i]);
//                 }
//             }

//             st = stemp;
//             if(s.length()>=2){
//                 st.push(s[0]);
//             }
//             for(int i =1; i<s.length(); i++){
//                 if(st.top()=='b' && s[i]=='a'){
//                     st.pop();
//                     ans+=y;
//                 }
//                 else{
//                     st.push(s[i]);
//                 }
//             }


//         }

//         return ans;


//     }


// };