/**
Runtime: 0 ms, Beats: 100%
Memory: 12.6 MB, Beats: 6.87%
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(root==nullptr) return {};

        vector<vector<int>> ret = {{root->val}};
        vector<TreeNode*> node = {root};
        int depth = 2;
        zigzag_BFS(depth, node, ret);
        return ret;
    }

    void zigzag_BFS(int& depth, vector<TreeNode*>& nodelist, vector<vector<int>>& ret){
        vector<int> tmpVal = {};
        vector<TreeNode*> tmpNode = {};
        for(auto& node:nodelist){
            if(depth % 2 == 0){
                if(node->right != nullptr){
                    tmpVal.emplace_back(node->right->val);
                    tmpNode.emplace_back(node->right);
                }
                if(node->left != nullptr){
                    tmpVal.emplace_back(node->left->val);
                    tmpNode.emplace_back(node->left);
                }
            }else{
                if(node->left != nullptr){
                    tmpVal.emplace_back(node->left->val);
                    tmpNode.emplace_back(node->left);
                }
                if(node->right != nullptr){
                    tmpVal.emplace_back(node->right->val);
                    tmpNode.emplace_back(node->right);
                }
            }
        }
        reverse(tmpNode.begin(), tmpNode.end());

        if(tmpVal.size())
            ret.emplace_back(tmpVal);
        if(tmpNode.size())
            zigzag_BFS(++depth, tmpNode, ret);
        
    }
};
