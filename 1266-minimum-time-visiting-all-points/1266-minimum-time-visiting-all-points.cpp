class Solution {
public:
    int maxDist(vector<int>& p1, vector<int> &p2){
        return max(abs(p2[0] - p1[0]), abs(p2[1] - p1[1]));
    }
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int ans = 0;
        vector<int> prev = points[0];

        for(int i = 1; i<points.size(); i++){
            ans+=maxDist(prev, points[i]);
            prev = points[i];
        }

        return ans;
    }
};