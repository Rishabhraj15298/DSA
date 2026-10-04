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
    // TreeNode* ans = NULL;
    // int solve(TreeNode*root , TreeNode*p , TreeNode*q){
    //     if(root == NULL){
    //         return 0;
    //     }

    //     int left = solve(root -> left , p , q );
    //     int right = solve(root -> right , p , q);
    //     int self = 0;
    //     if(root == p || root == q){
    //         self = 1;
    //     }
    //     int total = left + right + self;
    //     if(total == 2 && ans == NULL){
    //         ans = root;
    //     }
    //     return total;
    // }
    // TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    //     solve(root , p , q);
    //     return ans ;
    // }

    // ________________________________________________________________________________

    // unordered_map<TreeNode*, TreeNode*> mp;
    // unordered_map<TreeNode*, int> depth;

    // void build(TreeNode* root, TreeNode* parent, int d) {
    //     if (root == NULL) return;

    //     mp[root] = parent;
    //     depth[root] = d;

    //     build(root->left, root, d + 1);
    //     build(root->right, root, d + 1);
    // }

    // TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    //     mp.clear();
    //     depth.clear();

    //     build(root, root, 0);

    //     TreeNode* p1 = p;
    //     TreeNode* p2 = q;

    //     // Bring both nodes to the same depth
    //     while (depth[p1] > depth[p2]) {
    //         p1 = mp[p1];
    //     }

    //     while (depth[p2] > depth[p1]) {
    //         p2 = mp[p2];
    //     }

    //     // Move both nodes upward together
    //     while (p1 != p2) {
    //         p1 = mp[p1];
    //         p2 = mp[p2];
    //     }

    //     return p1;
    // }


    // ________________________________________________________________________________

    TreeNode* lowestCommonAncestor(TreeNode*root , TreeNode*p , TreeNode*q){
        if(root == NULL){
            return NULL;
        }

        if(root == p || root ==q){
            return root;
        }

        TreeNode*leftH = lowestCommonAncestor(root->left , p , q);
        TreeNode*rightH = lowestCommonAncestor(root->right , p ,q);

        if(leftH && rightH){
            return root;
        }
        return !leftH ? rightH : leftH;
    }

};