class Solution {
private: 
    void helper(vector<int>& cookies,vector<int>& children, int idx, int maxi, int& res, int & k){
        if(idx>=cookies.size()){
            res = min(res,maxi);
            return;
        }
        int cookie = cookies[idx];
        for(int i =0; i<k;i++){
            children[i]+=cookie;
            helper(cookies, children, idx+1, max(maxi,children[i]), res,k);
            children[i]-=cookie;
        }
    }
public:
    int distributeCookies(vector<int>& cookies, int k) {
        vector<int> children(k,0);

        int maxi = 0;
        int res = INT_MAX;

        helper(cookies,children,0,maxi,res,k);

        return res;
    }
};