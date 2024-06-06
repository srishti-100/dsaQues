class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int gs) {
        int n = hand.size();
        if(n%gs!=0){
            return false;
        }

        unordered_map<int,int> mp;
        sort(hand.begin(),hand.end());

        for(int i =0; i<n; i++){
            mp[hand[i]]++;
        }

        for(int i =0; i<n; i++){
            
            if(mp[hand[i]]>0){
                int s = 0;
                int start = hand[i];
                while(s<gs && mp[start]!=0){
                    mp[start]--;
                    s+=1;
                    start++;
                }
                if(s==gs){
                    continue;
                }
                else{
                    return false;
                }
            }
        }

        return true;

    }
};