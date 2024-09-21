class Solution {
public:
    static bool compare(int& a, int& b){
        string s = to_string(a);
        string t = to_string(b);

        return s<t;
    }
    vector<int> lexicalOrder(int n) {
        // vector<string> vec;
        // vector<int> ans;

        // for(int i =1; i<=n; i++){
        //     vec.push_back(to_string(i));
        // }
        // sort(vec.begin(), vec.end());

        // for(int i =0; i<n; i++){
        //     ans.push_back(stoi(vec[i]));
        // }
        // return ans;
        vector<int> ans;
        for(int i =1; i<=n; i++){
            ans.push_back(i);
        }

        sort(ans.begin(), ans.end(), compare);

        return ans;
    }
};