/**
Runtime: 40 ms, Beats: 50.47%
Memory: 15.8 MB, Beats: 99.47%
**/
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
    int ret;
    int pathSum(TreeNode* root, int targetSum) {
        if(root != nullptr){
            DFS(root, targetSum, ret);
            pathSum(root->left, targetSum);
            pathSum(root->right, targetSum);
        }
        return ret;
    }

    void DFS(TreeNode* root, long targetSum, int& ret){
        if(root == nullptr)
            return;
        if(targetSum == root->val){
            ret++;
        }

        DFS(root->left, targetSum - root->val, ret);
        DFS(root->right, targetSum - root->val, ret);
    
    }
};
