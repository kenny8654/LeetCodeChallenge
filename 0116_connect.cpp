/**
Runtime: 20 ms, Beats: 90.18%
Memory: 17.5 MB, Beats: 9.11%
**/
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        Node* lastNode;
        Node* currNode;
        queue<Node*> q;
        lastNode = root;
        q.push(root);
        while(1){
            currNode = q.front();
            q.pop();
            if(currNode == nullptr)
                break;
            q.push(currNode->left);
            q.push(currNode->right);
            if(currNode == lastNode){
                currNode->next = nullptr;
                lastNode = currNode->right;
            }else{
                currNode->next = q.front();
            }
        }

        return root;
    }
};
