class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {

        vector<vector<int>> ans;

        if (root == NULL) {
            return ans;
        }

        // HD -> Level -> Values
        map<int, map<int, vector<int>>> nodes;

        // Node -> {HD, Level}
        queue<pair<TreeNode*, pair<int, int>>> q;

        q.push(make_pair(root, make_pair(0, 0)));

        while (!q.empty()) {

            pair<TreeNode*, pair<int, int>> temp = q.front();
            q.pop();

            TreeNode* frontNode = temp.first;
            int hd = temp.second.first;
            int lvl = temp.second.second;

            nodes[hd][lvl].push_back(frontNode->val);

            // Left child
            if (frontNode->left) {
                q.push(make_pair(
                    frontNode->left,
                    make_pair(hd - 1, lvl + 1)
                ));
            }

            // Right child
            if (frontNode->right) {
                q.push(make_pair(
                    frontNode->right,
                    make_pair(hd + 1, lvl + 1)
                ));
            }
        }

        // HD → Level → Values
        for (auto i : nodes) {

            vector<int> column;

            for (auto j : i.second) {

                // Same HD and same level → smaller value first
                sort(j.second.begin(), j.second.end());

                for (auto k : j.second) {
                    column.push_back(k);
                }
            }

            ans.push_back(column);
        }

        return ans;
    }
};