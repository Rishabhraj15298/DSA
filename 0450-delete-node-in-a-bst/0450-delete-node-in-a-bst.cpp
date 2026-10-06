class Solution {
public:
    TreeNode* minVal(TreeNode* root) {
        TreeNode* tmp = root;
        while (tmp && tmp->left != NULL) {
            tmp = tmp->left;
        }
        return tmp;
    }

    TreeNode* deleteNode(TreeNode* root, int key) {
        // Base case: if the tree is empty
        if (root == NULL) {
            return root;
        }

        // Recur down the tree
        if (key < root->val) {
            root->left = deleteNode(root->left, key);
        } else if (key > root->val) {
            root->right = deleteNode(root->right, key);
        } else {
            // Node to be deleted has been found

            // Case 1: Node has no child
            if (root->left == NULL && root->right == NULL) {
                delete root;
                return NULL;
            }

            // Case 2: Node has only one child
            if (root->left == NULL) {
                TreeNode* temp = root->right;
                delete root;
                return temp;
            }
            if (root->right == NULL) {
                TreeNode* temp = root->left;
                delete root;
                return temp;
            }

            // Case 3: Node has two children
            TreeNode* temp = minVal(root->right); // Get the minimum value node from the right subtree
            root->val = temp->val; // Replace root's value with the smallest value from right subtree
            root->right = deleteNode(root->right, temp->val); // Delete the inorder successor
        }

        return root;
    }
};
