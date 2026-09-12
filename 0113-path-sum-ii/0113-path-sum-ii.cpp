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
    vector<vector<int>>ans;
     void solve(TreeNode*root , int sum , int target , vector<int>&diary){
        if(root == NULL){
            return;
        }
         diary.push_back(root->val);
        sum += root->val;
       
        if(root-> left == NULL && root -> right == NULL){
            if(sum == target){
                ans.push_back(diary);
                
                
            }
            diary.pop_back();
            return;

        }
        solve(root->left , sum , target , diary);
        solve(root->right , sum , target , diary);
        diary.pop_back();

    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int>diary;

        if(root == NULL){
            return ans;
        }
        solve(root ,0, targetSum, diary);
        return ans;
        
    }
};