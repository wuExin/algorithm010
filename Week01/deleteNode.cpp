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
    ListNode* deleteNode (ListNode* head, int val) {
        ListNode* cur = head;
        if (head->val == val) {
            return head->next;
        }
        while (head->next != NULL) {
            if (head->next->val == val) {
                ListNode* temp = head->next->next;
                delete head->next;
                head->next = temp;
                return cur;
            }
            head = head->next;
        }
        return cur;    
    }
};