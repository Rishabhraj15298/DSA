/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* ans = NULL;
    void solve(TreeNode* root , TreeNode* p , TreeNode*q){
        if(root == NULL){
            return ;
        }

        // Case 1 
        if(root == p || root == q){
            ans = root ;
            return ;
        }
        // case 2
        else if(root -> val < p->val){
            // search in right part 
            solve(root -> right , p , q);
        }
        // case 3
        else if(root->val > q-> val){
            // search in  the left part of the tree

            solve(root->left , p , q);
        }
        // case 4 -> p-> val < root->val < q->val
        else{
            ans = root ;
            return ;
        }

    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // we are making sure that p < q.
        if(p->val < q->val){
            solve(root , p , q);
        }
        else{
            solve(root , q , p);
        }

        return ans;
    }
};