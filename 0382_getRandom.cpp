/**
Runtime: 20 ms, Beats: 86.53%
Memory: 16.7 MB, Beats: 58.84%
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
private:
    int mSize = 0;
    ListNode* mHead;
public:
    Solution(ListNode* head) :mHead(head) {
        ListNode* cur = head;
        while(nullptr != cur){
            mSize++;
            cur = cur->next;
        }
    }
    
    int getRandom() {
        int random = rand() % mSize;
        ListNode* cur = mHead;
        while(random--){
            cur = cur->next;
        }
        return cur->val;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */
