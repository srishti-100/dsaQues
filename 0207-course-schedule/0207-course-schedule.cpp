class Solution {
private:
    void inDegreeFind(int n, vector<vector<int>>& adj, vector<int>& inDegree){
        // for(auto x: adj){
        //     inDegree[x[0]]++;
        // }
        for(int i =0; i<n; i++){
	        for(auto x: adj[i]){
	            inDegree[x]++;
	        }
	    }
    }


public:
    bool canFinish(int n, vector<vector<int>>& adj) {
        vector<int> inDegree(n,0);
        vector<int> ans;
        

        vector<vector<int>> adjList(n);
        for(auto x: adj){
            adjList[x[1]].push_back(x[0]);
        }
        inDegreeFind(n,adjList,inDegree);
        queue<int> q;
        for(int i =0; i<n; i++){
            if(inDegree[i]==0) q.push(i);
        }

        while(!q.empty()){
            int t = q.front();
            ans.push_back(t);
            q.pop();
            for(auto x: adjList[t]){
                inDegree[x]--;
                if(inDegree[x]==0) q.push(x);
            }
        }
        if(ans.size()==n) return true;
        return false;
    }
};