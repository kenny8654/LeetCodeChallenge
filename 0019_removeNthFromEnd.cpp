/**
Runtime: 3 ms, faster than 91.78% of C++ online submissions for Remove Nth Node From End of List.
Memory Usage: 10.6 MB, less than 74.97% of C++ online submissions for Remove Nth Node From End of List.
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
      ListNode* dummy = new ListNode(0, head);
      ListNode* l = dummy;
      ListNode* r = dummy;
      n += 1;
      while(n--)
        r = r -> next;
      while(r != NULL){
        l = l -> next;
        r = r -> next;
      }
      l -> next = l -> next -> next; 
      return dummy->next;
    }
};
