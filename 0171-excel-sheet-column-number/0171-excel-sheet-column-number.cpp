class Solution {
public:
    int titleToNumber(string s) {
        int j = 0;
        int n = s.size();
        int ans = 0;

        for(int i =n-1; i>=0; i--){
                ans = ans+ pow(26,j)*(int(s[i]-'A')+1);
                j++;
        }
        return ans;
    }
};