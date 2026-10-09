class Solution {
public:
    void floodFill(vector<vector<int>>& image, int i, int j,int old,int color) {
        if(i<0||i>=image.size()||j<0||j>=image[0].size()||image[i][j]!=old)
            return;

        image[i][j] = color;

        floodFill(image,i+1,j,old,color);
        floodFill(image,i-1,j,old,color);
        floodFill(image,i,j+1,old,color);
        floodFill(image,i,j-1,old,color);
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int old = image[sr][sc];

        if(old == color)
            return image;

        floodFill(image,sr,sc,old,color);

        return image;
    }
};