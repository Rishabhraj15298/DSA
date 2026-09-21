class Solution {
public:
    typedef pair<int , int > P;
    int m , n;
    bool isSafe(int x , int y,vector<vector<int>>& grid ){
        if(x >= 0 && x<m && y >=0 && y<n && grid[x][y] == 1){
            return true;
        }
        return false;

    }

    vector<vector<int>>directions{{-1,0} , {1,0} , {0,-1} , {0,1} };
    int orangesRotting(vector<vector<int>>& grid) {
         m = grid.size();
         n = grid[0].size();

        int freshCount = 0;
        queue<P>q;

        for(int i =0;i<m;i++){
            for(int j = 0;j<n;j++){
                if(grid[i][j] == 2){
                    q.push({i,j});
                }
                else if( grid[i][j] == 1){
                    freshCount++;
                }
                else{
                    continue;
                }
            }
        }

        if(freshCount  == 0 ){
            return 0;
        }
        int minutes = 0;
        while(!q.empty()){
            int s = q.size();

            while(s--){
                auto curr = q.front();

                int x = curr.first;
                int y = curr.second;
                q.pop();
                
                for(auto &d : directions){
                    int x_ = x+d[0];
                    int y_ = y+d[1];

                    if(isSafe(x_,y_ , grid)){
                        grid[x_][y_] = 2;
                        q.push({x_,y_});
                        freshCount--;
                    }
                }


            }

            minutes++;
        }
        return freshCount == 0 ? (minutes -1) : -1;

        
    }
};