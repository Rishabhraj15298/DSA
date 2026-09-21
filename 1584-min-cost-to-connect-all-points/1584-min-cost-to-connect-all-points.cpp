class Solution {
public:
    typedef pair<int, int> P;
    vector<int>parent;
    vector<int>rank;
    int find(int x){
        if(parent[x] == x ){
            return x;


        }

        return parent[x] = find(parent[x]);
    }

    void Union (int x , int y ){
        int x_parent = find(x);
        int y_parent = find (y);

        if(x_parent == y_parent){
            return ;

        }
        if(rank[x_parent] > rank[y_parent]){
            parent[y_parent] = x_parent;

        }
        else if(rank[x_parent] < rank[y_parent]){
            parent[x_parent] = y_parent;
        }
        else{
            parent[x_parent] = y_parent;
        }
    }



    int kruskalAlgo(vector<vector<int>> & vec){
        int sum = 0;

        for(auto &curr : vec){
            int u = curr[0];
            int v = curr[1];
            int wt = curr[2];

            int p1 = find(u);
            int p2 = find(v);

            if(p1 != p2){
                Union(u , v);
                sum+=wt;
            }
        }

        return sum;
    }

    int minCostConnectPoints(vector<vector<int>>& points) {
        
        int n = points.size();
        parent.resize(n);
        rank.resize(n , -1);

        for(int i =0;i<n;i++){
            parent[i] = i;
        }

       vector<vector<P>>adj(n);

        // Build complete graph
        for(int i = 0; i < n; i++) {

            for(int j = i + 1; j < n; j++) {

                int wt = abs(points[i][0] - points[j][0])
                       + abs(points[i][1] - points[j][1]);

                // Store INDEX, not x-coordinate
                adj[i].push_back({j, wt});
                adj[j].push_back({i, wt});
            }
        }

        // // Prim's Algorithm
        // priority_queue<P, vector<P>, greater<P>> pq;

        // vector<bool> inMST(n, false);

        // pq.push({0, 0});

        // int sum = 0;

        // while(!pq.empty()) {

        //     auto curr = pq.top();
        //     pq.pop();

        //     int d = curr.first;
        //     int node = curr.second;

        //     if(inMST[node]) {
        //         continue;
        //     }

        //     inMST[node] = true;
        //     sum += d;

        //     for(auto &it : adj[node]) {

        //         int adjNode = it.first;
        //         int dist = it.second;

        //         if(!inMST[adjNode]) {
        //             pq.push({dist, adjNode});
        //         }
        //     }
        // }

        // return sum;


        vector<vector<int>>vec;

        for(int u = 0 ; u < n ; u++){
            for(auto &it : adj[u]){
                int v = it.first;
                int wt = it.second;

                vec.push_back({u , v , wt});
            }

        }
        auto comparator = [&] (vector<int>&vec1 , vector<int>&vec2){
            return vec1[2] < vec2[2];
        } ;  
        sort(begin (vec) , end(vec) , comparator);

        return kruskalAlgo (vec);
    }
};