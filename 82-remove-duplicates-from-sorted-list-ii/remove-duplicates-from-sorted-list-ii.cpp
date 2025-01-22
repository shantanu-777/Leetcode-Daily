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
    ListNode* deleteDuplicates(ListNode* head) {
        // empty || single node
        if (!head || !head->next) return head;

        ListNode* backward = NULL;
        ListNode* curr = head;
        ListNode* forward = head->next;

        while (forward) {
            // if pair is found
            if (curr->val == forward->val) {
                // find the range
                ListNode* tail = forward;
                while (forward && curr->val == forward->val) {
                    tail = forward;
                    forward = forward->next;
                }
                // backward != NULL -> 1st case
                if (!backward) {
                    // update the backward and head
                    head = forward;
                    // isolate pair and delete
                    tail->next = NULL;
                    // delete
                    ListNode* temp = curr;
                    while (temp) {
                        ListNode* temp2 = temp;
                        temp = temp->next;
                        delete temp2;
                    }
                    // update the curr and forward
                    // backward still NULL
                    curr = forward;
                    if (curr) forward = curr->next;
                }
                // in-b/w case
                else {
                    // connect
                    backward->next = forward;
                    // isolate pair and delete
                    tail->next = NULL;
                    // delete
                    ListNode* temp = curr;
                    while (temp) {
                        ListNode* temp2 = temp;
                        temp = temp->next;
                        delete temp2;
                    }
                    // update
                    curr = backward->next;
                    if (curr) forward = curr->next;
                }
            }
            // pair not found
            else {
                backward = curr;
                curr = forward;
                forward = curr->next;
            }
        }

        return head;
    }
};