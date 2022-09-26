/**
Runtime: 0 ms, faster than 100.00% of C++ online submissions for Swap Nodes in Pairs.
Memory Usage: 7.7 MB, less than 6.60% of C++ online submissions for Swap Nodes in Pairs.
**/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode* dummy = new ListNode(0, head);
        ListNode* curr = dummy;
        while(curr != NULL && curr->next != NULL && curr->next->next!=NULL){
            ListNode* tmpNext = curr->next;
            ListNode* tmpthreeNext = curr->next->next->next;
            curr->next = curr->next->next;
            curr = curr->next;
            curr->next = tmpNext;
            curr = curr->next;
            curr->next = tmpthreeNext;
        }
        return dummy->next;
    }
};
