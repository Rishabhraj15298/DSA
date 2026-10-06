class Solution {
public:
    TreeNode* solve(TreeNode* root, int val, TreeNode* temp) {

        if (root == NULL)
            return temp;

        if (root->val > val) {
            if(root->left == NULL){
                root->left = temp;
            }
            else{
                solve(root->left, val, temp);
            }
            
        }
        else {
            if(root->right == NULL){

                root->right = temp;
            }
            else{
                solve(root->right, val, temp);
            }
            
        }

        return root;
    }

    TreeNode* insertIntoBST(TreeNode* root, int val) {

        TreeNode* temp = new TreeNode(val);

        if (root == NULL)
            return temp;

        return solve(root, val, temp);
    }
};