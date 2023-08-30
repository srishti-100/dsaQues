struct TrieNode{
    vector<TrieNode*> bits;

    TrieNode(){
        for(int i=0; i<2; i++){
            bits.push_back(NULL);
        }
    }
};

class Trie{
    TrieNode* root;

    public:
        Trie(){
            root = new TrieNode();
        }
    
    void insert(int num){
        TrieNode* temp = root;

        for(int i = 31; i>=0; i--){
            int bit = (num>>i)&1;

            if(temp->bits[bit]==NULL){
                temp->bits[bit] = new TrieNode();
            }
            temp= temp->bits[bit];
        }
    }

    int maxFind(int num){
        TrieNode* temp = root;

        int maxi = 0;

        for(int i= 31; i>=0; i--){
            int bit = (num>>i)&1;

            if(temp->bits[1-bit]!=NULL){
                maxi = maxi | (1<<i);
                temp = temp->bits[!bit];
            }
            else{
                temp = temp->bits[bit];
            }
        }
        return maxi;
    }
};

class Solution {
public:
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {

        /*
        vector<int> ans(queries.size(),-1);

        for(int i =0; i<queries.size();i++){
            for(int j =0; j<nums.size(); j++){
                if(nums[j]<=queries[i][1]){
                    ans[i] = max(ans[i], nums[j]^queries[i][0]);
                }
            }
        }
        return ans;
        */

        int n = nums.size();
        int m = queries.size();
        sort(nums.begin(), nums.end());
        vector<int> ans(m,0);
        vector<pair<int,pair<int,int>>> q;
       
        for(int i =0; i<m; i++) {
            q.push_back({queries[i][1],{queries[i][0],i}});
            
        }

        sort(q.begin(),q.end());
        Trie trie;
        int idx=0;
        for(int i =0; i<m; i++){

            while(idx<n && nums[idx]<=q[i].first){
                    trie.insert(nums[idx]);
                    idx++;
            }
            if(idx!=0)
                ans[q[i].second.second]=trie.maxFind(q[i].second.first);
                else ans[q[i].second.second]=-1;

        }
        return ans;
    }
};