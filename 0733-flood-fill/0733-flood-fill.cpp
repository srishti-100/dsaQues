class Solution {
public:
    void helper(int initialColor, int sr, int sc, int rows, int cols, vector<vector<int>>& image, int color, vector<vector<int>>& visited){
        if(sr<0 || sr>=rows || sc<0 || sc>=cols || image[sr][sc]!=initialColor || visited[sr][sc]==1){
            return;
        }
        visited[sr][sc]=1;
        
                    helper(initialColor,sr+1,sc,rows,cols,image,color,visited);
                    helper(initialColor,sr-1,sc,rows,cols,image,color,visited);
                    helper(initialColor,sr,sc+1,rows,cols,image,color,visited);
                    helper(initialColor,sr,sc-1,rows,cols,image,color,visited);
                
            
        

        image[sr][sc]=color;


    }


    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int m = image.size();
        int n = image[0].size();
        vector<vector<int>>visited(m,vector<int>(n,-1));

        helper(image[sr][sc],sr,sc,m,n,image,color,visited);
        
        return image;
    }
};