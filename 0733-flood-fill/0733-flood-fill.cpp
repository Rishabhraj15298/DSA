class Solution {
public:
    int m , n;
    void dfs(vector<vector<int>>&image , int i , int j , int color , int ogColor){
        // base case 
        if(i<0||i>=m||j<0||j>=n||image[i][j]!=ogColor||image[i][j]==color){
            return ;
        }
        
        // visited mark kro
        image[i][j] = color;
        dfs(image , i+1 , j , color , ogColor);
        dfs(image , i-1 , j , color , ogColor);
        dfs(image , i , j+1 , color , ogColor);
        dfs(image , i , j-1 , color , ogColor);

    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        m = image.size();
        n = image[0].size();
        dfs(image , sr ,sc, color , image[sr][sc]);
        return image;
        
        
    }
};