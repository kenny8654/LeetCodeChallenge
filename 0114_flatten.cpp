/**
Runtime: 3 ms, Beats: 93.97%
Memory: 12.9 MB, Beats: 14.18%
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
    stack<TreeNode*> mStack;
    TreeNode* pCurr;
public:
    void flatten(TreeNode* root) {
        pCurr = new TreeNode();
        mStack.push(root);
        while(!mStack.empty()){
            TreeNode* curr = mStack.top();
            mStack.pop();
            preOrder(curr);
            pCurr->right = curr;
            pCurr->left = nullptr;
            pCurr = pCurr->right;
        }
    }

    void preOrder(TreeNode* root){
        if(root == nullptr) return;

        if(root->right != nullptr){
            mStack.push(root->right);
        }
        if(root->left != nullptr){
            mStack.push(root->left);
        }
    }
};
