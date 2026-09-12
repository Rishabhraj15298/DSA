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
    stack<TreeNode * >asc;
    stack<TreeNode*> desc;

    int getSmall(){
        TreeNode* small = asc.top();
        asc.pop();

        TreeNode* rightChild = small -> right;
        while(rightChild != NULL){
            asc.push(rightChild);
            rightChild = rightChild->left;
        }

        return small->val;
    }


    int getBig(){
        TreeNode* big = desc.top();
        desc.pop();

        TreeNode*leftChild = big->left;
        while(leftChild != NULL){
            desc.push(leftChild);
            leftChild = leftChild->right;
        }

        return big->val;
    }

    bool findTarget(TreeNode* root, int k) {
        TreeNode* t = root ;
        while(t){
            asc.push(t);
            t= t->left;
        }
        t = root ;
        while(t){
            desc.push(t);
            t= t->right;
        }

        int s = getSmall();
        int e = getBig();
        while(s<e){
            if((s+e) == k){
                return true;
            }
            else if((s+e)<k){
                s = getSmall();// ye hamare liye next small value laa kr dega.
            }
            else{
                e = getBig();
            }
        }
        return false;
    }
};