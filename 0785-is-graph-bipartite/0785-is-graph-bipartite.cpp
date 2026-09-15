class Solution {
public:
    // bool DFSbipartite(unordered_map<int , vector<int>>&adj ,int curr , vector<int>&color , int currColor){

    //     color[curr] = currColor;

    //     for(int &v : adj[curr]){
    //         if(color[v] == color [curr]){
    //             return false;
    //         }

    //         if(color[v] == -1){
    //             int colorOfV = 1 - currColor;

    //             if(DFSbipartite(adj , v , color , colorOfV) == false){
    //                 return false;
    //             } 
    //         }
    //     }
    //     return true;
    // }
    bool BFSbipartite(unordered_map<int , vector<int>>&adj , int curr , vector<int>&color , int currColor){

        queue<int>q;
        q.push(curr);
        color[curr] = currColor;

        while(!q.empty()){
            int u = q.front();
            q.pop();

            for(int &v : adj[u]){
                if(color[v] == color[u]){
                    return false;
                }

                if(color[v ] == -1){
                    
                    q.push(v);
                    color[v ] = 1-color[u];
                }
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        unordered_map<int , vector<int>>adj;
        int n = graph.size();
        for(int i =0;i<n;i++){
            for(int j = 0;j<graph[i].size();j++){
                adj[i].push_back(graph[i][j]);
            }
        }

        vector<int>color(n , -1);
        for(int i =0;i<n;i++){
            if(color[i] == -1){
                if(BFSbipartite(adj , i , color , 1) == false){
                    return false;
                }
            }
        }
        return true;
    }
};