class Solution {
    // KAHN'S ALGORITHM 
public:
    vector<int>TopoSort(unordered_map<int , vector<int>> &adj , int n, vector<int>&indegree){

        queue<int>q;
        vector<int>res;
        int cnt = 0;
        
        for(int i =0;i<n;i++){
            if(indegree[i] == 0){
                q.push(i);
             

            }
        }

        while(!q.empty()){
            int u = q.front();
            res.push_back(u);
            q.pop();
            cnt++;
            for(int &v : adj[u]){
                indegree[v]--;

                if(indegree[v] == 0){
                    q.push(v);
                    
                }
            }
        }

        if(cnt == n ){
            return res;
        }
        return {};
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        
        unordered_map<int , vector<int>> adj;
        vector<int>indegree(numCourses , 0);

        for(auto &i : prerequisites){
            int u = i[1];
            int v = i[0];

            adj[u].push_back(v);

            indegree[v]++;
        }

        return TopoSort(adj , numCourses , indegree);
    }
};