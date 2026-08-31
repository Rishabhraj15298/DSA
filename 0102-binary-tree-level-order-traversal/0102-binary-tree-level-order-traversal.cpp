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
    void levelOrder(TreeNode*root , vector<vector<int>>&ans){
        if(root == NULL)return ;
        queue<TreeNode*>q;

        q.push(root);

        while(!q.empty()){
            vector<int>temp;
            int lvl_size = q.size();
            while(lvl_size--){
                TreeNode*curr = q.front();
                q.pop();

                temp.push_back(curr->val);
                if(curr-> left)q.push(curr->left);
                if(curr->right)q.push(curr->right);

            }

            ans.push_back(temp);
        }
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>>ans;

        levelOrder(root , ans);

        return ans;
    }
};