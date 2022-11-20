/**
Runtime: 15 ms, Beats: 85.3%
Memory: 10.4 MB, Beats: 75.32%
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
    ListNode* oddEvenList(ListNode* head) {
        if(nullptr == head) return head;
        ListNode* pOdd = head;
        ListNode* pEven = new ListNode();
        ListNode* pEvenDummyHead = pEven;
        
        while(nullptr != pEven){
            pEven->next = pOdd->next;
            pEven = pEven->next;
            if(pEven == nullptr || pEven->next==nullptr) break;
            pOdd->next = pEven->next;
            pOdd = pOdd->next;     
        }
        pOdd->next = pEvenDummyHead->next;
        return head;
    }
};
