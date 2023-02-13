/**
Runtime: 37 ms, Beats: 81.27%
Memory: 33.5 MB, Beats: 24.60%
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
private:
    int sum;
public:
    TreeNode* convertBST(TreeNode* root) {
        sum = 0;
        DFS(root);
        return root;
    }

    void DFS(TreeNode* root){
        if(nullptr == root) return;

        DFS(root->right);
        sum += root->val;
        root->val = sum;
        DFS(root->left);
    }
};
