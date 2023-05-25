/**
Runtime, 5 ms, Beats: 65.48%
Memory: 9.8 MB, Beats: 72.90%
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
    int maxAncestorDiff(TreeNode* root) {
        return findDiff(root, INT_MAX, INT_MIN);
    }

    int findDiff(TreeNode* root, int curr_min, int curr_max){
        if(!root)
            return curr_max - curr_min;
        curr_min = min(curr_min, root->val);
        curr_max = max(curr_max, root->val);
        return max(findDiff(root->left, curr_min, curr_max), findDiff(root->right, curr_min, curr_max));
    }
};
