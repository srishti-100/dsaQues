class Solution {
public:
    char findTheDifference(string s, string t) {
        unordered_map<char,int> mp1;

        for(auto c: s){
            mp1[c]++;
        }
        
        for(auto c: t){
            if(mp1.find(c)==mp1.end()){
                return c;
            }
            if(mp1[c]>1){
                mp1[c]--;
            }
            else{
                mp1.erase(c);
            }
        }

        return ' ';
    }
};