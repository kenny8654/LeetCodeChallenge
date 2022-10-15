/**
Runtime: 50 ms, faster than 83.33% of C++ online submissions for Reorder List.
Memory Usage: 18.6 MB, less than 17.17% of C++ online submissions for Reorder List.
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
    void reorderList(ListNode* head) {
        ListNode* curr=head;
        int size = 0;
        stack<ListNode*> st;
        while(curr != NULL){
            st.push(curr);
            size++;
            curr = curr->next;
        }
        curr = head;
        for(int i=0; i<size/2; i++){
            ListNode* tmp = curr->next;
            curr->next = st.top();
            st.top()->next = tmp;
            st.pop();
            curr = curr->next->next;
        }
        curr->next = NULL;
        return;
    }
};
