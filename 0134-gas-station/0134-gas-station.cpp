class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int t_gas = 0 ;
        int t_cost = 0;
        int n = gas.size();
        for(int i =0;i<n;i++){
            t_gas += gas[i];
            t_cost += cost[i];
        }

        if(t_gas < t_cost){
            return -1;
        }

        int curr_gas = 0; 
        int st_index = 0;

        for(int i =0;i<n;i++){
            curr_gas += gas[i]-cost[i];

            if(curr_gas < 0){
                st_index = i+1;
                curr_gas = 0;

            }
        }

        return st_index;

    }
};