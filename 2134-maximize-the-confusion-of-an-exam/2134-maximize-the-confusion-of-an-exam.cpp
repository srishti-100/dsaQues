class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        int l = 0;
        int n = answerKey.length();
        int maxLength = 0;

        unordered_map<char,int>mp;

        int i =0; int j =0;

        while(j<n){
            mp[answerKey[j]]++;

            if(min(mp['T'],mp['F'])>k){
                mp[answerKey[i]]--;
                i++;
            }
            maxLength = max(maxLength,j-i+1);
            j++;
        }

        return maxLength;
    }
};