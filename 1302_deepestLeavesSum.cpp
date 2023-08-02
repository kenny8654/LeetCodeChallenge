/**
Runtime: 70ms
Beats 99.29%of users with C++
Memory: 61.80mb
Beats 38.56%of users with C++
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
    int deepestLeavesSum(TreeNode* root) {
        int ret = 0, size = 0;
        queue<TreeNode*> que;
        que.push(root);
        while(!que.empty()){
            ret = 0;
            size = que.size();
            for(int i=0; i<size; i++){
                auto cur = que.front();
                ret += cur->val;
                que.pop();
                if(cur->left)
                    que.push(cur->left);
                if(cur->right)
                    que.push(cur->right);
            }
        }
        return ret;
    }
};
