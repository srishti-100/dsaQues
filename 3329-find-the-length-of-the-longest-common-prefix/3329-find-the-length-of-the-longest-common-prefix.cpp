class Solution {
public:
    int prefix(int a, int b){
        string s = to_string(a);
        string t = to_string(b);

        if(s.length() >t.length()){
            string p = s;
            s = t;
            t = p;
        }

        int len = 0;
        for(int i =0; i<s.length(); i++){
            if(s[i]==t[i]){
                len++;
            }
            else{
                break;
            }
        }
        return len;
    }

    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        /*
        int maxSize = 0;
        for(int i =0; i<arr1.size(); i++){
            for(int j =0; j<arr2.size(); j++){
                maxSize= max(maxSize,prefix(arr1[i],arr2[j]));
            }
        }
        return maxSize;
        */

        set<string> s;
        for(int i =0; i<arr1.size(); i++){
            string e = to_string(arr1[i]);
            for(int j =0; j<e.size(); j++){
                s.insert(e.substr(0,j+1));
            }
        }

        int ans = 0;
        for(int i =0; i<arr2.size(); i++){
            string e = to_string(arr2[i]);
            for(int j = 0; j<e.size(); j++){
                if(s.find(e.substr(0,j+1))!=s.end()){
                    ans = max(ans, j+1);
                }
            }
        }
        return ans;
    }
};