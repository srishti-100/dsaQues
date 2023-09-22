class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int maxAlt = 0;
        int alt = 0;
        for(auto i: gain){
            alt+=i;
            if(alt>maxAlt) maxAlt = alt;
        }
        return maxAlt;
    }
};