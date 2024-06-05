class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        
        int n = words.size();
        vector<vector<int>> hash(n,vector<int>(26,0));

        for(int i =0; i<n; i++){
            for(auto ch:words[i]){
                hash[i][ch-'a']++;
            }
        }

        vector<string> ans;

        vector<int> minfreq(26,INT_MAX);

        for(int i =0; i<26; i++){
            for(int j = 0; j<n; j++){
                minfreq[i] = min(minfreq[i],hash[j][i]);
            }
        }

        for(int i =0; i<26; i++){
            if(minfreq[i]!=INT_MAX){
                for(int j=0; j<minfreq[i]; j++){
                    ans.push_back(string(1,'a'+i));
                }
            }
        }

        return ans;

    }
};