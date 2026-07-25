class Solution {
public:
    int maxProduct(int n) {
        vector<int>ans;
        while(n>0){
            int rem = n%10;
            ans.push_back(rem);

            n/=10;

        }
        int p = ans.size();
        sort(ans.begin() , ans.end());
        return ans[p-1] * ans[p-2];
    }
};