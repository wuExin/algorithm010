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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (head == NULL || head->next == NULL) {
            return head;
        }
        ListNode* tail = head;
        for (int i = 0; i<k; i++) {
            if(tail == NULL) {
                return head;
            }
            tail = tail->next;
        }

        ListNode* newHead = reverse(head,tail);
        head->next = reverseKGroup(tail,k);
        return newHead;
    }

    ListNode* reverse(ListNode* head,ListNode* tail) {
        ListNode* prev = NULL;
        ListNode* curr = head;
        while (curr != tail) {
            ListNode* temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        return prev;
    }

};