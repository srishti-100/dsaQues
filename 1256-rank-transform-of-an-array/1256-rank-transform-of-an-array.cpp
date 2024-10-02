class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        if(arr.size()==0){
            return {};
        }
        vector<int> duplicate = arr;

        sort(duplicate.begin(), duplicate.end());
        map<int,int> mp;

        mp[duplicate[0]] = 1;

        for(int i =1; i<duplicate.size(); i++){
            if(duplicate[i]>duplicate[i-1]){
                mp[duplicate[i]] = mp[duplicate[i-1]]+1;
            }
            else{
                mp[duplicate[i]]= mp[duplicate[i-1]];
            }
        }

        vector<int> res;
        for(int x: arr){
            res.push_back(mp[x]);
        }

        return res;

    }
};