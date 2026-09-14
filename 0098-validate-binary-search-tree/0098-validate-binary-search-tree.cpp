class Solution {
public:

    bool isBST(TreeNode* root, long long mini, long long maxi) {

        if (root == NULL) {
            return true;
        }

        if (root->val <= mini || root->val >= maxi) {
            return false;
        }

        bool left = isBST(root->left, mini, root->val);
        bool right = isBST(root->right, root->val, maxi);

        return left && right;
    }

    bool isValidBST(TreeNode* root) {

        return isBST(root, LLONG_MIN, LLONG_MAX);
    }
};