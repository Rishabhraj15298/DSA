class Solution {
public:
    typedef pair<int, int> P;

    int minCostConnectPoints(vector<vector<int>>& points) {

        int n = points.size();

        unordered_map<int, vector<vector<int>>> adj;

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

        // Prim's Algorithm
        priority_queue<P, vector<P>, greater<P>> pq;

        vector<bool> inMST(n, false);

        pq.push({0, 0});

        int sum = 0;

        while(!pq.empty()) {

            auto curr = pq.top();
            pq.pop();

            int d = curr.first;
            int node = curr.second;

            if(inMST[node]) {
                continue;
            }

            inMST[node] = true;
            sum += d;

            for(auto &it : adj[node]) {

                int adjNode = it[0];
                int dist = it[1];

                if(!inMST[adjNode]) {
                    pq.push({dist, adjNode});
                }
            }
        }

        return sum;
    }
};