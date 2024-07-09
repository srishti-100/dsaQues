class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image) {
        int n = image.size();
        for(int i =0; i<n; i++){

            int j =0;
            int k = image[i].size()-1;
            while(j<=k){
                int num = image[i][j]^1;
                image[i][j]= image[i][k]^1;
                image[i][k] = num;
                j++;
                k--;
            }
        }
        return image;
    }
};