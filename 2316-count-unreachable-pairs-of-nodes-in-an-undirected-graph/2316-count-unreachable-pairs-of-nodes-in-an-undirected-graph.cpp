class Solution {
public:
     vector<int>parent;
    vector<int> rank;   

    int find(int x){
        if(x == parent[x]){
            return x;

        }
        return parent[x] = find(parent[x]);
    }

    void Union(int x , int y ){
        int x_parent = find(x);
        int y_parent = find(y);

        if(x_parent == y_parent ){
            return ;
        }
        if(rank[x_parent] > rank[y_parent]){
            parent[y_parent ]= x_parent;
        }
        else if(rank[x_parent ] < rank[y_parent]){
            parent[x_parent ]= y_parent;
        }
        else {
            parent[x_parent ]= y_parent;
            rank[y_parent]++;
        }
    }
    long long countPairs(int n, vector<vector<int>>& edges) {
        
         parent.resize(n);
        rank.resize(n , 0);

        for(int i =0;i<n;i++){
            parent [i] = i;
        }

        // component bnao 
        for(auto &vec : edges){
            int x = vec[0];
            int y = vec[1];

            Union(x,y);
        }

        // populate the map

        unordered_map<int , int >mp;

        for(int i =0;i<n;i++){
            int papaji = find(i);
            mp[papaji]++;
        }

        // find ans from the map 
        int rem = n;
        long long result = 0;
        for(auto &it : mp){
            long long size = it.second;

            result += (size) * (rem - size);

            rem-=size;
        }

        return result ;
        

    }
};