class Solution {
public:
    void dfs(vector<vector<int>>& image, int r, int c, int color, int originalColor) {
        int m = image.size();
        int n = image[0].size();

        // Boundary check and color match check
        if (r < 0 || r >= m || c < 0 || c >= n || image[r][c] != originalColor)
            return;

        // Change the color
        image[r][c] = color;

        // Recursively call for 4 directions
        dfs(image, r+1, c, color, originalColor);
        dfs(image, r-1, c, color, originalColor);
        dfs(image, r, c+1, color, originalColor);
        dfs(image, r, c-1, color, originalColor);
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int originalColor = image[sr][sc];
        if (originalColor != color) {
            dfs(image, sr, sc, color, originalColor);
        }
        return image;

    }
   
};