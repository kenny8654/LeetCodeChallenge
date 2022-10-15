/**
Runtime: 3 ms, faster than 90.88% of C++ online submissions for Binary Tree Level Order Traversal.
Memory Usage: 12.4 MB, less than 84.66% of C++ online submissions for Binary Tree Level Order Traversal.
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ret;
        if(root == NULL) return ret;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            vector<int> tmp;
            int size = q.size();
            for(int i=0; i<size; i++){
                TreeNode* front = q.front();
                if(front->left != NULL)
                    q.push(front->left);
                if(front->right != NULL)
                    q.push(front->right);
                tmp.emplace_back(front->val);
                q.pop();
            }
            ret.emplace_back(tmp);
        }
        return ret;
    }
};
