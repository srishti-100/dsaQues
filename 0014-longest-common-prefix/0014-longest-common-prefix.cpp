class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string s = strs[0];
        int n = strs.size();

        int count = 0;
        int j = 0;
        while(j<s.length()){
            int cnt = 0;
            for(int i =1; i<n; i++){
                if(strs[i][j]!=s[j]){
                    break;
                }
                cnt++;
            }
            if(cnt==n-1) {
                count++;
                j++;
            }
            else{
                break;
            }
        
        }

        return s.substr(0,count);
    }
};