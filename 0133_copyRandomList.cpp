/**
Runtime: 0 ms, Beats: 100%
Memory: 11.2 MB, Beats: 88.36%
**/
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head == NULL) return nullptr;
        Node* pRet = new Node(0);
        Node* pCurr = pRet;
        Node* pOriginCurr = head;
        unordered_map<Node*, Node*> map;

        while(pOriginCurr != NULL){
            pCurr->next = new Node(pOriginCurr->val);
            pCurr = pCurr->next;
            map[pOriginCurr] = pCurr;
            pOriginCurr = pOriginCurr->next;
        }

        pCurr = pRet->next;
        while(head != NULL){
            pCurr->random = map[head->random];
            pCurr = pCurr->next;
            head = head->next;
        }
        return pRet->next;
    }
};
