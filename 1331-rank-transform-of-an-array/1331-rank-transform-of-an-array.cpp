
class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int> sorted = arr;
        sort(sorted.begin(), sorted.end());

        unordered_map<int, int> rank;
        int r = 1;

        for (int x : sorted) {
            if (rank.find(x) == rank.end()) {
                rank[x] = r++;
            }
        }

        vector<int> result;
        for (int x : arr) {
            result.push_back(rank[x]);
        }

        return result;
    }
};
