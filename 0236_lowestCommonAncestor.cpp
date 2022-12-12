/**
Runtime: 23 ms, Beats: 74.55%
Memory: 14.5 MB, Beats: 17%
**/
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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode*& p, TreeNode*& q) {
        TreeNode* ret = nullptr;
        DFS(root, p, q, ret);
        return ret;
    }

    int DFS(TreeNode* root, TreeNode*& p, TreeNode*& q, TreeNode*& ret){
        if(root == nullptr) return 0;
        int flag = 0;
        if(root == p) 
            flag |= (1<<1);
        if(root == q)
            flag |= 1;
        
        flag |= DFS(root->left, p, q, ret);
        flag |= DFS(root->right, p, q, ret);
        if(flag == 3)
            ret = (ret == nullptr)? root: ret;
        return flag;
        
        
    }
};
