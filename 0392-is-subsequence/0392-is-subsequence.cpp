class Solution {
public:
    bool isSubsequence(string s, string t) {
        
        int i =0;
        int j =0;
        int n = t.size();
        int m = s.size();
        if(m==0){
            return true;
        }
        if(m!=0 && n==0) return false;
        while(i<m && t.length()>0){
            int idx = t.find(s[i]);
            if(idx==string::npos) return false;
            t = t.substr(idx+1);
            i++;

        }

        if(i<m) return false;
        return true;
        

    }
};