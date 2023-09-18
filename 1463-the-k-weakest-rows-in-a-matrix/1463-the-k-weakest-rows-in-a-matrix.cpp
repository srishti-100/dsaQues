typedef pair<int,int> p;
class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        priority_queue<p> pq;

        for(int i =0; i<mat.size(); i++){
            int cnt = 0;
            for(int j = 0; j<mat[i].size(); j++){
                cnt+=(mat[i][j]==1)?1:0;
            }

            pair<int,int> q;
            q.first = cnt;
            q.second = i;
            pq.push(q);
            if(pq.size()>k){
                pq.pop();
            }

        }  

        vector<int> ans(k);

        for(int i = k-1; i>=0; i--){
            ans[i] = pq.top().second;
            pq.pop();
        }

        return ans;



    }
};