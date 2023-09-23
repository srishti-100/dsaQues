class Solution {
public:
    bool closeStrings(string word1, string word2) {
        map<char,int> mp1;
        map<char,int> mp2;

        for(auto i: word1){
            mp1[i]++;
        }

        for(auto i: word2){
            mp2[i]++;
        }


        if(mp1.size()!=mp2.size()) return false;

        vector<char> v1;
        for(auto i: mp1){
            v1.push_back(i.first);
        }

        vector<char> v2;
        for(auto i: mp2){
            v2.push_back(i.first);
        }
        sort(v1.begin(),v1.end());
        sort(v2.begin(),v2.end());
        if(v1!=v2) return false;

        vector<int> cnt1;
        for(auto i: mp1){
            cnt1.push_back(i.second);
        }

        vector<int> cnt2;
        for(auto i: mp2){
            cnt2.push_back(i.second);
        }
        sort(cnt1.begin(),cnt1.end());
        sort(cnt2.begin(),cnt2.end());
        if(cnt1!=cnt2) return false;

        return true;

    }
};