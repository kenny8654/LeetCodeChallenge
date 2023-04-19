/**
Runtime: 18 ms, Beats: 81.96%
Memory: 24.9 MB, Beats: 67.73%
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
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth == 1)
            return new TreeNode(val, root, nullptr);
        
        DFS(root, val, depth, 1);
        return root;
    }

    void DFS(TreeNode* root, int &val, int &depth, int cur_depth){
        if(root == nullptr) 
            return;
        
        cur_depth++;
        if(cur_depth == depth){
            root->left = new TreeNode(val, root->left, nullptr);
            root->right = new TreeNode(val, nullptr, root->right);
        }else{
            DFS(root->left, val, depth, cur_depth);
            DFS(root->right, val, depth, cur_depth);
        }
    }
};
