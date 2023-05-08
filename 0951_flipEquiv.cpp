/**
Runtime: 3 ms, Beats: 73.26%
Memory: 12 MB, Beats: 98.23%
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
    bool flipEquiv(TreeNode* root1, TreeNode* root2) {
        return checkEquiv(root1, root2);
    }

    bool checkEquiv(TreeNode* root1, TreeNode* root2){
        if(root1 == nullptr && root2 == nullptr)
            return true;
        if(root1 == nullptr || root2 == nullptr)
            return false;
        if(root1->val != root2->val)
            return false;
        
        if(root1->left == nullptr || root1->right == nullptr)
            moveLeaf2Left(root1);
        if(root2->left == nullptr || root2->right == nullptr)
            moveLeaf2Left(root2);
        if(root1->left!=nullptr && root2->left!=nullptr && root1->left->val!=root2->left->val)
            swap(root1->left, root1->right);

        return checkEquiv(root1->left, root2->left) && checkEquiv(root1->right, root2->right);
        
    }

    void moveLeaf2Left(TreeNode* root){
        if(root->left==nullptr && root->right==nullptr)
            return;
        if(root->left != nullptr)
            return;

        swap(root->left, root->right);
    }
};
