/**
Runtime: 24 ms, Beats: 80.1%
Memory: 24 MB, Beats: 87.17%
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
    int kthSmallest(TreeNode* root, int k) {
        int ret;
        DFS(root, k, ret);
        return ret;
    }

    void DFS(TreeNode* root, int& cnt, int& ret){
        if(root == nullptr || cnt<=0)
            return;

        DFS(root->left, cnt, ret);
        cnt--;
        if(cnt == 0){
            ret = root->val;
            return;
        }
        DFS(root->right, cnt, ret);
    }
};
