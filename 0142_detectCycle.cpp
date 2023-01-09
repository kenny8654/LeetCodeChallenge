/**
Runtime: 8 ms, Beats: 88.6%
Memory: 7.4 MB, Beats: 94.43%
**/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        bool isCycle = false;
        ListNode* hare = head;
        ListNode* tortoise = head;

        while(hare!=nullptr && hare->next!=nullptr && tortoise!=nullptr){
            hare = hare->next->next;
            tortoise = tortoise->next;
            if(hare == tortoise){
                isCycle = true;
                break;
            }
        }
        if(!isCycle)
            return nullptr;
        else{
            tortoise = head;
            while(1){
                if(hare == tortoise)
                    return hare;
                hare = hare->next;
                tortoise = tortoise->next;
            }
        }
    }
};
