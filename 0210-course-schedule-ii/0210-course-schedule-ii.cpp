class Solution {
    // KAHN'S ALGORITHM 
public:
    bool hasCycle;
    // vector<int>TopoSort(unordered_map<int , vector<int>> &adj , int n, vector<int>&indegree){

    //     queue<int>q;
    //     vector<int>res;
    //     int cnt = 0;
        
    //     for(int i =0;i<n;i++){
    //         if(indegree[i] == 0){
    //             q.push(i);
             

    //         }
    //     }

    //     while(!q.empty()){
    //         int u = q.front();
    //         res.push_back(u);
    //         q.pop();
    //         cnt++;
    //         for(int &v : adj[u]){
    //             indegree[v]--;

    //             if(indegree[v] == 0){
    //                 q.push(v);
                    
    //             }
    //         }
    //     }

    //     if(cnt == n ){
    //         return res;
    //     }
    //     return {};
    // }
    void DFS(unordered_map<int , vector<int>> &adj , int u , vector<bool>&visited , vector<bool>&inRecursion , stack<int>&st){

        visited[u] = true;
        inRecursion[u]  = true;

        for(int &v : adj[u]){
            if(!visited[v]  ){
                DFS(adj , v , visited , inRecursion , st);
            }
            if(visited[v] == true && inRecursion[v] == true){
                hasCycle = true;
                return;
            }
        }

        st.push(u);
        inRecursion[u] = false;
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        
        unordered_map<int , vector<int>> adj;
        // vector<int>indegree(numCourses , 0);
        vector<bool>visited(numCourses , false);
        vector<bool >inRecursion(numCourses , false);
        hasCycle = false;

        for(auto &i : prerequisites){
            int u = i[1];
            int v = i[0];

            adj[u].push_back(v);

            
        }
        stack<int>st;
        for(int i =0;i<numCourses ;i++){
            if(!visited[i] ){
                DFS(adj , i , visited , inRecursion , st);
            }

        }

        if(hasCycle){
            return {};
        }
        vector<int>res;
        while(!st.empty()){
            res.push_back(st.top());
            st.pop();
        }

        return res;

        // return TopoSort(adj , numCourses , indegree);


    }
};