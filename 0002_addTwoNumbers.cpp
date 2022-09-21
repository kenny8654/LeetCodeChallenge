/**
Runtime: 35 ms, faster than 92.94% of C++ online submissions for Add Two Numbers.
Memory Usage: 71.5 MB, less than 51.80% of C++ online submissions for Add Two Numbers.
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
      ListNode* ret = new ListNode(0);
      ListNode* curr = ret;
      bool carry = false;
      while(l1 != NULL || l2 != NULL){
        int l1val = l1? l1->val : 0;
        int l2val = l2? l2->val : 0;
        int sum = l1val + l2val + carry;
        curr->next = new ListNode(sum % 10);
        carry = sum / 10;
        if(l1 != NULL)
          l1 = l1->next;
        if(l2 != NULL)
          l2 = l2->next;
        curr = curr->next;
      }
      if(carry)
        curr->next = new ListNode(1);
      return ret->next;
    }
};