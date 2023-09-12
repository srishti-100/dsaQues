#include<bits/stdc++.h>
class Solution {
private:
    
public:
    static bool cmp(pair<char, int>&a,  pair<char, int>& b)
        {
            return a.second > b.second;
        }
    static void sortMap(unordered_map<char, int>& mp){
        vector<pair<char, int> > A;
 
        for (auto& it : mp) {
            A.push_back(it);
        }
    
        sort(A.begin(), A.end(), cmp);
        mp.clear();

        for(auto it: A){
            mp[it.first] = it.second; 
        }
    }
    int minDeletions(string s) {
        vector<int> f(26,0);
        
        for(int i =0; i<s.length(); i++){
            f[s[i]-'a']++;
        } 

        sort(f.begin(), f.end());
    
        set<int> freq;
        int i = 25;
        int cnt=0;
        while(i>=0 && f[i]!=0 ){
            while(freq.find(f[i])!=freq.end()){
                if(f[i]==0) break;
                f[i]--;
                cnt++;
            }
            freq.insert(f[i]);
            i--;
        }

        return cnt;
    }
};