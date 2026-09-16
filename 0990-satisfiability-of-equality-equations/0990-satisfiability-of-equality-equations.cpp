class Solution {
public:
    vector<int> parent;
    vector<int> rank;

    int find(int x) {
        if (x == parent[x]) {
            return x;
        }

        return parent[x] = find(parent[x]);
    }

    void Union(int x, int y) {

        int x_parent = find(x);
        int y_parent = find(y);

        if (x_parent == y_parent) {
            return;
        }

        if (rank[x_parent] > rank[y_parent]) {
            parent[y_parent] = x_parent;
        }
        else if (rank[x_parent] < rank[y_parent]) {
            parent[x_parent] = y_parent;
        }
        else {
            parent[x_parent] = y_parent;
            rank[y_parent]++;
        }
    }

    bool equationsPossible(vector<string>& equations) {

        parent.resize(26);
        rank.assign(26, 0);

        // Initially, every character is its own parent
        for (int i = 0; i < 26; i++) {
            parent[i] = i;
        }

        // Step 1: Process all equality equations
        for (auto &eq : equations) {

            if (eq[1] == '=') {

                int x = eq[0] - 'a';
                int y = eq[3] - 'a';

                Union(x, y);
            }
        }

        // Step 2: Check all inequality equations
        for (auto &eq : equations) {

            if (eq[1] == '!') {

                int x = eq[0] - 'a';
                int y = eq[3] - 'a';

                if (find(x) == find(y)) {
                    return false;
                }
            }
        }

        return true;
    }
};