/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int solve(TreeNode*root , int &maxSum){
        if(root == NULL){
            return 0;
        }

        int l = solve(root->left , maxSum);
        int r = solve(root->right , maxSum);

        int neeche_hi_max = l + r + root->val;

        int root_hi_max = root->val;

        int dono_me_se_ek = max(l,r) + root->val;

        maxSum = max({maxSum , neeche_hi_max ,root_hi_max , dono_me_se_ek});
        // isme hmlog neeche hi max waale ko nhi return kr skte qki jb ans niche hi h toh upar q jaayenge..

        return max(root_hi_max , dono_me_se_ek) ;
    }
    int maxPathSum(TreeNode* root) {
        
        int maxSum = INT_MIN;

        solve(root , maxSum);

        return maxSum;

        
        
    }
};