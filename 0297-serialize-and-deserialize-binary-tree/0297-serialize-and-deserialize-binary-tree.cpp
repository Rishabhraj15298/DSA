/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
   
   string serialize(TreeNode* root) {
    if (root == NULL) return "null";

    string result;
    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        TreeNode* curr = q.front();
        q.pop();

        if (curr == NULL) {
            result += "null,";
            continue;
        }

        result += to_string(curr->val) + ",";

        q.push(curr->left);
        q.push(curr->right);
    }

    return result;
}

    // Decodes your encoded data to tree.

    TreeNode* deserialize(string data) {

        if (data == "null")
            return NULL;
        stringstream ss(data);
        string value;

        getline(ss, value, ',');
        queue<TreeNode*> q;
        TreeNode* root = new TreeNode(stoi(value));
        q.push(root);

        while (!q.empty()) {
            TreeNode* curr = q.front();
            q.pop();

            // Read left
            if (!getline(ss, value, ','))
                break;

            if (value != "null") {
                curr->left = new TreeNode(stoi(value));
                q.push(curr->left);
            }

            // Read right ;
            if (!getline(ss, value, ','))
                break;

            if (value != "null") {
                curr->right = new TreeNode(stoi(value));
                q.push(curr->right);
            }
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));