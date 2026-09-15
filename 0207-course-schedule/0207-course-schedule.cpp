class Solution {
public:
    // bool TopologicalSort(unordered_map<int , vector<int>>&adj , int n , vector<int>&indegree){

        
    //     if(cnt == n){
    //         return true;
    //     }
    //     else{
    //         return false;
    //     }
    // }
    bool isCycleDFS(unordered_map <int , vector<int>>&adj , int u , vector<bool>&visited , vector<bool>&inRecursion){

        visited[u] = true;

        inRecursion[u ]= true;
        
        for(int &v : adj[u]){
            if(!visited[v] && isCycleDFS(adj , v, visited , inRecursion)){
                return true;
            }
            else if (inRecursion[v] == true){
                return true;
            }
        }
        inRecursion[u] = false;
        return false;

    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        
       

    //     unordered_map<int , vector<int >>adj;
    //     vector<bool>visited(numCourses , false);
    //     stack<int>st;


    //     for(auto & i : prerequisites){
    //         int u = i[1];
    //         int v = i[0];

    //         adj[u].push_back(v);


    //     }

    //     return TopologicalSort(adj , numCourses , visited);
    // }

    unordered_map<int , vector<int>>adj;
    vector<bool>inRecursion(numCourses , false);
    vector<bool>visited(numCourses , false);

        for(auto & i : prerequisites){
            int u = i[1];
            int v = i[0];

            adj[u].push_back(v);


        }

        for(int i = 0 ;i<numCourses ;i++){
            if(!visited[i] && isCycleDFS(adj , i , visited , inRecursion)){
                return false; // qki cycle detect ho gya h
            }

        }
        return true;
    }
    
};