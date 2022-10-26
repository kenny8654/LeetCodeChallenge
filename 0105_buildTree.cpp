/**
Runtime: 56 ms, faster than 36.76% of C++ online submissions for Construct Binary Tree from Preorder and Inorder Traversal.
Memory Usage: 25.9 MB, less than 92.96% of C++ online submissions for Construct Binary Tree from Preorder and Inorder Traversal.
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
    int pre_idx = 0;
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return createTree(preorder, inorder, 0, inorder.size()-1);
    }

    TreeNode* createTree(vector<int>& preorder, vector<int>& inorder, int in_start, int in_end){
        if(in_start > in_end) return nullptr;
        
        for(int i=in_start ; i<=in_end; i++){
            if(preorder[pre_idx] == inorder[i]){
                TreeNode* curr = new TreeNode(preorder[pre_idx]);
                pre_idx++;
                curr->left = createTree(preorder, inorder, in_start, i-1);
                curr->right = createTree(preorder, inorder, i+1, in_end);
                return curr;
            }
        }
        return nullptr;
    }
};
