class Solution {
public:
    vector<int> relocateMarbles(vector<int>& nums, vector<int>& moveFrom, vector<int>& moveTo) {
        set<int> s;
        for(auto x: nums){
            s.insert(x);
        }

        for(int i =0; i<moveFrom.size(); i++){
            s.erase(moveFrom[i]);
            s.insert(moveTo[i]);
        }

        vector<int> ans(s.begin(),s.end());
        return ans;
    }
};