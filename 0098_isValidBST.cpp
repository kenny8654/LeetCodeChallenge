/**
Runtime: 10 ms, faster than 95.35% of C++ online submissions for Validate Binary Search Tree.
Memory Usage: 21.7 MB, less than 69.67% of C++ online submissions for Validate Binary Search Tree.
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
    bool isValidBST(TreeNode* root) {
        vector<int> inorder;
        buildInorderTree(root, inorder);
        if(inorder.size() == 1) return true;
        for(int i=1; i<inorder.size(); i++)
            if(inorder[i-1] >= inorder[i]) return false;
        return true;
    }

    void buildInorderTree(TreeNode* node, vector<int>& inorder){
        if(!node) return;
        buildInorderTree(node->left, inorder);
        inorder.emplace_back(node->val);
        buildInorderTree(node->right, inorder);
    }
};
