class Solution {
public:
    int compress(vector<char>& chars) {
        int i =0;
        string res;
        while(i<chars.size()){
            char c = chars[i];
            int j = i+1;
            int cnt = 1;
            while(j<chars.size() && chars[j]==c){
                j++;
                cnt++;
            }
            res+=c;
            if(cnt>1){
                res+=to_string(cnt);
            }
            i = j;
        }
        chars.clear();
        for(int i =0; i<res.size(); i++){
            chars.push_back(res[i]);
        }
        return res.size();
    }
};