class Solution {
public:
    int m , n;
    // ++++++++++++++++++++++++DFS++++++++++++++++++++++++++++=
    // void dfs(vector<vector<int>>&image , int i , int j , int color , int ogColor){
    //     // base case 
    //     if(i<0||i>=m||j<0||j>=n||image[i][j]!=ogColor||image[i][j]==color){
    //         return ;
    //     }
        
    //     // visited mark kro
    //     image[i][j] = color;
    //     dfs(image , i+1 , j , color , ogColor);
    //     dfs(image , i-1 , j , color , ogColor);
    //     dfs(image , i , j+1 , color , ogColor);
    //     dfs(image , i , j-1 , color , ogColor);

    // }
    // vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
    //     m = image.size();
    //     n = image[0].size();
    //     dfs(image , sr ,sc, color , image[sr][sc]);
    //     return image;
        
        
    // }

    // ++++++++++++++++++++++++++++BFS+++++++++++++++++++++++++++++
    bool isValid(int i , int j , vector<vector<int>>&image , int color , int ogColor){
        if(i<0||i>=m||j<0||j>=n||image[i][j]!=ogColor||image[i][j]==color){
            return false;
        }
        return true;

    }
    vector<vector<int>> directions = {
    {-1, 0},  // Up
    {1, 0},   // Down
    {0, -1},  // Left
    {0, 1}    // Right
};
    vector<vector<int>>floodFill(vector<vector<int>>&image , int i , int j , int color){
        m = image.size();
        n = image[0].size();

        queue<pair<int,int>>q;
        int ogColor = image[i][j];
        q.push({i , j});
        image[i][j] = color;
        if(ogColor == color )return image;
        while(!q.empty()){
            auto temp = q.front();
            q.pop();
            int x = temp.first;
            int y = temp.second;
            

            for(auto& d : directions){
                int x_ = x+d[0];
                int y_ = y+d[1];

                if(isValid(x_,y_, image , color , ogColor)){
                    image[x_][y_]=color;
                    q.push({x_,y_});
                }


            }
        }

        return image;


    }
};