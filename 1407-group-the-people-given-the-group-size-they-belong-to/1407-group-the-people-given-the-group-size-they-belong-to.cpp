class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& gp) {
        //My Solution
        //Worst Case time Complexity
        //O(n^2)
        /*
        unordered_map<int, vector<int> > mp;
        int n = gp.size();
        for(int i =0; i<n; i++){
            mp[gp[i]].push_back(i);
        }

        vector<vector<int>> ans;

        for(auto it:mp){
            vector<int> v = it.second;

            int s = it.first;
            int partition = ceil(v.size()/s);

            vector<int> temp;
            int elemCnt = 0;
            for(auto i: v){
                if(temp.size()< s){
                    temp.push_back(i);
                }
                else{
                    ans.push_back(temp);
                    elemCnt++;
                    temp.clear();
                    temp.push_back(i);
                }
            }

            if(elemCnt < partition){
                ans.push_back(temp);
            }

        }

        return ans;
        */

        //editorial solution
        //Worst Case time Complexity
        //O(n)
        int n = gp.size();
        unordered_map<int, vector<int> > mp;
        vector<vector<int>> ans; 
        for(int i =0; i<n; i++){
            mp[gp[i]].push_back(i);
            if(mp[gp[i]].size()==gp[i]){
                ans.push_back(mp[gp[i]]);
                mp[gp[i]].clear();
            }
        }

        return ans;



    }
};