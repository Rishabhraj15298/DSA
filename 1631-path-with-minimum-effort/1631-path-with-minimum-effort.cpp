class Solution {
public:
    typedef pair<int , pair<int , int >> P;

    int m , n ;

    bool isSafe(int x , int y){
        if(x>=0 && x<m && y>=0 && y<n){
            return true;
        }
        return false;
    }

    int minimumEffortPath(vector<vector<int>>& heights) {

        vector<vector<int>>directions{{0,1} , {1,0} , {-1 , 0} , {0,-1}};
        
         m = heights.size();
         n = heights[0].size();

        priority_queue<P , vector<P> , greater<P>>pq;
        vector<vector<int>>result( m , vector<int> (n , INT_MAX));

        result[0][0] = 0;
        pq.push({0 , {0,0}});

        

        while(!pq.empty()){
            int dist = pq.top().first;
            auto curr = pq.top().second;
            pq.pop();
            int x = curr.first;
            int y = curr.second;
            

            for(auto it : directions){
                int x_ = x + it[0];
                int y_ = y + it[1];
                
                if(isSafe(x_ , y_)){
                    int absHeight = abs(heights[x][y] - heights[x_][y_]);
                    int maxi = max(dist, absHeight);

                    if(maxi < result[x_][y_]){
                        result[x_][y_] = maxi;
                        pq.push({maxi , {x_ , y_}});
                    }

                }
            }



        }
        return result[m-1][n-1];
    }
};