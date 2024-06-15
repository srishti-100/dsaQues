class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int n = profits.size();
        vector<std::pair<int,int>> projects;

        for(int i =0; i<n; i++){
            projects.push_back(make_pair(capital[i],profits[i]));
        }
        sort(projects.begin(),projects.end());

        priority_queue<int> maxHeap;
        int i =0;

        while(k>0){
            while(i<n && projects[i].first<=w){
                maxHeap.push(projects[i].second);
                i++;
            }
            if(maxHeap.empty()) {
                break;
            }

            w+=maxHeap.top();
            maxHeap.pop();
            k--;
        }
        return w;


    }
};