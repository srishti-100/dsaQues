#include<bits/stdc++.h>
class Solution {
public:
    int minDeletions(string s) {
        unordered_map<char,int> mp;
        
        for(int i =0; i<s.length(); i++){
            mp[s[i]]++;
        } 
    
        set<int> freq;
        int cnt=0;
        for(auto it: mp){
            while(it.second>0 && freq.find(it.second)!=freq.end()){
                it.second--;
                cnt++;
            }
            freq.insert(it.second);
        }

        return cnt;
    }
};