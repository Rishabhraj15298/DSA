class Solution {
public:
    int sum = 0;

    void solve(TreeNode* root, int current) {

        if (root == NULL) {
            return;
        }

        int num = current * 10 + root->val;

        // Leaf node
        if (root->left == NULL && root->right == NULL) {
            sum += num;
            return;
        }

        solve(root->left, num);
        solve(root->right, num);
    }

    int sumNumbers(TreeNode* root) {

        if (root == NULL) {
            return 0;
        }

        solve(root, 0);

        return sum;
    }
};