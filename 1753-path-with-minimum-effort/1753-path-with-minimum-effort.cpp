typedef pair<int,pair<int,int>> p;

class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        priority_queue<p, vector<p>, greater<p>> pq;
        int rows = heights.size();
        int cols = heights[0].size();
        vector<vector<int>> distance(rows, vector<int>(cols,INT_MAX));

        vector<int> delRows{-1,0,1,0};
        vector<int> delCols{0,1,0,-1};
        distance[0][0]=0;
        pq.push({0,{0,0}});

        while(!pq.empty()){
            int diff = pq.top().first;
            int r = pq.top().second.first;
            int c = pq.top().second.second;
            pq.pop();

            if(r==rows-1 && c == cols-1) return diff;
            for(int i =0; i<4; i++){
                
                    int nr = r+ delRows[i];
                    int nc = c + delCols[i];

                    if(nr>=0 && nr<rows && nc>=0 && nc<cols){
                        int d = max(abs(heights[r][c]-heights[nr][nc]),diff);
                        if(d<distance[nr][nc]){
                            distance[nr][nc] = d;

                            pq.push({d,{nr,nc}});
                        }
                    }
                
            }
        }
        return -1;
    }
};